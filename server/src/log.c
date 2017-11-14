/*
** log.c for PSU_2016_zappy
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Wed Jun 28 15:19:09 2017 Gauthier Harnisch
** Last update	Sun Jul 02 17:18:26 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	send_graph(t_serv *serv, char *msg)
{
  int	i;

  i = 0;
  while (i < serv->nb_cli)
    {
      if (serv->cli[i] != NULL && serv->cli[i]->flag == GRAPHIC)
	send_cli(serv->cli[i], msg);
      i++;
    }
}

int	cmp_team(char *str, t_serv *serv)
{
  int	i;

  i = 0;
  while (i < serv->nb_team)
    {
      if (strcmp(str, serv->team[i]->name) == 0)
	return (i);
      i++;
    }
  return (-1);
}

void	pnw(t_serv *serv, int i)
{
  char	*str;

  if (!(str = (char *)malloc(MAXLINE)))
    error(84, "malloc fail");
  sprintf(str, "pnw %d %d %d %d %d %s\n", serv->cli[i]->id,
	  serv->cli[i]->pos->x, serv->cli[i]->pos->y, serv->cli[i]->dir,
	  serv->cli[i]->level, serv->cli[i]->team->name);
  send_graph(serv, str);
  free(str);
}

void	lAI(t_serv *serv, int i, t_team *team)
{
  char  *str;

  if (!(str = (char *)malloc(MAXLINE)))
    error(84, "malloc fail");
  sprintf(str, "%d\n", team->max_nb_players - team->nb_user);
  send_cli(serv->cli[i], str);
  sprintf(str, "%d %d\n", serv->sizex, serv->sizey);
  send_cli(serv->cli[i], str);
  free(str);
}

void	logg(t_serv *serv, int i)
{
  if (strcmp(serv->buf, "GRAPHIC") == 0)
    {
      serv->cli[i]->flag = GRAPHIC;
      msz(serv, i, NULL);
      sgt(serv, i, NULL);
      bct(serv, i, NULL);
      tna(serv, i, NULL);
      serv->cli[i]->expect = (handle)cmd;
    }
  else
    if (cmp_team(serv->buf, serv) >= 0 &&
      (serv->team[cmp_team(serv->buf, serv)]->max_nb_players -
      serv->team[cmp_team(serv->buf, serv)]->nb_user) != 0)
      {
        add_to_team(serv->team[cmp_team(serv->buf, serv)], serv->cli[i]);
        serv->cli[i]->flag = AI;
        serv->cli[i]->expect = (handle)cmd;
        find_egg(serv, i);
        pnw(serv, i);
        lAI(serv, i, serv->team[cmp_team(serv->buf, serv)]);
      }
    else
      unkown_cmd(serv, i, NULL);
  free(serv->buf);
}
