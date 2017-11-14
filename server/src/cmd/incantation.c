/*
** Incantation.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Wed Jun 21 11:39:41 2017 Sébastien Blineau
** Last update	Sun Jul 02 23:03:01 2017 Gauthier Harnisch
*/

#include "zappy.h"

static incant lvl_tab[]=
  {
    level1,
    level2,
    level3,
    level4,
    level5,
    level6,
    level7,
    level8,
    NULL
  };

void		levelup(t_serv *serv, int i)
{
  int		j;
  int		n;
  char	*msg;

  j = (n = -1);
  if ((msg = (char *)malloc(MAXLINE)) == NULL)
    error(84, "Malloc failed");
  sprintf(msg,  "Current level: %d\n", serv->cli[i]->level);
  while (serv->cli[++j])
    if (serv->cli[j] && serv->cli[i]->pos->x == serv->cli[j]->pos->x &&
      serv->cli[i]->pos->y == serv->cli[j]->pos->y)
      {
        serv->cli[j]->level += 1;
        send_cli(serv->cli[j], msg);
      }
  while (serv->cli[i]->pos->ressources[++n])
    serv->cli[i]->pos->ressources[n] = 0;
  free(msg);
}

int		check_nummap(t_serv *serv, int i)
{
  int		j;
  int		k;

  j = -1;
  k = 0;
  while (++j < serv->nb_cli)
    if (serv->cli[j] && serv->cli[i]->pos->x == serv->cli[j]->pos->x &&
	serv->cli[i]->pos->x == serv->cli[j]->pos->y)
      {
	k++;
	if (serv->cli[i] && serv->cli[j]->level != serv->cli[i]->level)
	  k += 1000;
      }
  return (k);
}

void	send_message_incant_begin(t_serv *serv, int i)
{
  char	*msg;
  int	j;

  if ((msg = (char *)malloc(MAXLINE)) == NULL)
    error(84, "Malloc failed\n");
  sprintf(msg, "pic %d %d %d %d", serv->cli[i]->pos->x, serv->cli[i]->pos->y,
	  serv->cli[i]->level, serv->cli[i]->id);
  send_graph(serv, msg);
  j = -1;
  while (++j < serv->nb_cli)
    if (serv->cli[j] && serv->cli[j]->pos->x == serv->cli[i]->pos->x &&
	serv->cli[j]->pos->y == serv->cli[i]->pos->y && i != j)
      {
	send_graph(serv, (char *)" ");
	send_graph(serv, (char *)itoa(j));
      }
  send_graph(serv, (char *)"\n");
  free(msg);
}

void	send_message_incant_end(t_serv *serv, int i, int good)
{
  char	*msg;
  int	n;

  if ((msg = (char *)malloc(MAXLINE)) == NULL)
    error(84, "Malloc failed\n");
  sprintf(msg, "pie %d %d %d\n", serv->cli[i]->pos->x, serv->cli[i]->pos->y,
	  good);
  send_graph(serv, msg);
  n = -1;
  while (serv->cli[++n])
    {
      if (serv->cli[i] && serv->cli[n]->pos == serv->cli[i]->pos)
	{
	  sprintf(msg, "plv %d %d\n", n, serv->cli[n]->level);
	  send_graph(serv, msg);
	}
    }
  n = -1;
  while (++n != 7)
    serv->cli[i]->pos->ressources[n] = 0;
  sprintf(msg, "bct %d %d 0 0 0 0 0 0 0\n", serv->cli[i]->pos->x,
	  serv->cli[i]->pos->y);
  send_graph(serv, msg);
  free(msg);
}

void		incantation(t_serv *serv, int i, char **tab)
{
  int	message_printed;
  int	lvl;

  (void)tab;
  if (serv->cli[i]->incanting_end != 0 && serv->cli[i]->incanting_end
      != serv->turn)
    {
      send_cli(serv->cli[i], (char *)"ko\n");
      return ;
    }
  message_printed = 0;
  lvl = serv->cli[i]->level;
  if (serv->cli[i]->incanting_end == 0)
    {
      send_message_incant_begin(serv, i);
      serv->cli[i]->cycle_to_exec = serv->turn + 300;
      serv->cli[i]->func = NULL;
      message_printed = 1;
    }
  lvl_tab[serv->cli[i]->level - 1](serv, i);
  if (message_printed == 0)
    send_message_incant_end(serv, i, (lvl == serv->cli[i]->level));
}
