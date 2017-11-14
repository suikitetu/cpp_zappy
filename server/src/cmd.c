/*
** cmd.c for PSU_2016_myirc
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Mon May 29 16:06:14 2017 Gauthier Harnisch
** Last update	Sun Jul 02 22:55:02 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	unkown_cmd(t_serv *serv, int i, char **tab)
{
  (void)tab;
  if (serv->cli[i] && serv->cli[i]->flag == GRAPHIC)
    send_cli(serv->cli[i], (char *)"suc\n");
  else
    send_cli(serv->cli[i], (char *)"ko\n");
}

t_cmd	cmd_tab[] =
  {
    {"FORWARD*", forward, 7, AI},
    {"RIGHT*", right, 7, AI},
    {"LEFT*", left, 7, AI},
    {"LOOK*", look, 7, AI},
    {"INVENTORY*", inventory, 1, AI},
    {"BROADCAST*", broadcast, 7, AI},
    {"CONNECT_NBR*", connect_nbr, 0, AI},
    {"FORK*", mfork, 42, AI},
    {"EJECT*", eject, 7, AI},
    {"TAKE*", take, 7, AI},
    {"SET*", set, 7, AI},
    {"INCANTATION*", incantation, 0, AI},
    {"CMD_EXAMPLE*", cmd_example, 1, AI},
    {"MSZ*", msz, 0, GRAPHIC},
    {"BCT*", bctxy, 0, GRAPHIC},
    {"MCT*", bct, 0, GRAPHIC},
    {"SGT*", sgt, 0, GRAPHIC},
    {"SST*", sst, 0, GRAPHIC},
    {"TNA*", tna, 0, GRAPHIC},
    {"*", unkown_cmd, 1, AI | GRAPHIC}
  };

static void	del_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
}

int	pop_cmd(t_serv *serv, int i)
{
  if (serv->cli[i] && serv->cli[i]->cycle_to_exec == -1
    && (serv->buf = buff_pop_line(serv->cli[i]->read)))
    {
      printf("%ld:exec:%i:\"%s\"\n", serv->turn, serv->cli[i]->id, serv->buf);
      serv->cli[i]->expect(serv, i);
    }
  return (0);
}

int	exec_cmd(t_serv *serv, int k)
{
  char	**tab;
  char	*tmp;

  serv->cli[k]->cycle_to_exec = -1;
  if (serv->cli[k] && (!serv->cli[k]->func || !serv->cli[k]->msg))
    return (1);
  tab = str_tab((tmp = clean_str(serv->cli[k]->msg, ALLOW)));
  free(tmp);
  serv->cli[k]->func(serv, k, tab);
  free(serv->cli[k]->msg);
  del_tab(tab);
  return (pop_cmd(serv, k));
}

int	cmd(t_serv *serv, int k)
{
  int	i;
  char	*command;

  command = strupcase(serv->buf);
  i = 0;
  if (serv->cli[k]->cycle_to_exec != -1)
    return (1);
  while (!((cmd_tab[i].flag & serv->cli[k]->flag) == serv->cli[k]->flag)
  || (cmd_tab[i].name && !match(command, (char *)cmd_tab[i].name)))
    i++;
  free(command);
  if (!(strcmp(cmd_tab[i].name, "Fork*")))
    graph_msg_fork(serv, k);
  serv->cli[k]->func = cmd_tab[i].func;
  serv->cli[k]->cycle_to_exec = serv->turn + cmd_tab[i].time;
  serv->cli[k]->msg = serv->buf;
  if (cmd_tab[i].time == 0)
    return (exec_cmd(serv, k));
  return (0);
}
