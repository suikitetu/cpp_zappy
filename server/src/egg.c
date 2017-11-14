/*
** egg.c for PSU_2016_zappy
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Fri Jun 30 15:20:58 2017 Gauthier Harnisch
** Last update	Sat Jul 01 14:31:38 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	new_egg(t_serv *serv, int k)
{
  static int	next_id = 0;
  int	i;

  i = 0;
  while (i <= serv->nb_egg && serv->egg[i] != NULL)
    i++;
  if (!(serv->egg[i] = (t_egg *)malloc(sizeof(t_egg))))
    error(84, "malloc failed");
  serv->egg[i]->team = serv->cli[k]->team;
  serv->egg[i]->pos = serv->cli[k]->pos;
  serv->egg[i]->food = 10;
  serv->egg[i]->life = 126;
  serv->egg[i]->id = next_id++;
  serv->egg[i]->hatched = 0;
  serv->egg[i]->turn_to_hatch = serv->turn + 600;
  printf("new egg from:%i\n", serv->egg[i]->id);
  if (i < serv->nb_egg)
    return ;
  serv->nb_egg++;
  if (!(serv->egg = (t_egg **)realloc(serv->egg, sizeof(t_egg *)
  * (serv->nb_egg + 1))))
    error(84, "realloc failed");
  serv->egg[serv->nb_egg] = NULL;
}

void	 check_egg(t_serv *serv)
{
  int	i;
  char	*msg;

  i = 0;
  if ((msg = (char *)malloc(MAXLINE)) == NULL)
    error(84, "Malloc failed\n");
  while (i < serv->nb_egg)
    {
      if (serv->egg[i]->turn_to_hatch <= serv->turn)
	{
	  sprintf(msg, "eht %d\n", serv->egg[i]->id);
	  send_graph(serv, msg);
	}
      i++;
    }
  free(msg);
}

void	remove_egg(t_serv *serv, int k)
{
  if (k > serv->nb_egg || serv->egg[k] == NULL)
    error(84, "attempt of removing a non-existing egg\n");
  free(serv->egg[k]);
  serv->egg[k] = NULL;
}

static void	send_message_graph(t_serv *serv, t_egg *egg)
{
  char	*msg;

  if ((msg = (char *)malloc(MAXLINE)) == NULL)
    error(84, "malloc failed\n");
  sprintf(msg, "ebo %d\n", egg->id);
  send_graph(serv, msg);
  free(msg);
}

void	find_egg(t_serv *serv, int i)
{
  int	k;
  t_egg	*best;
  int	nb_best;

  k = -1;
  best = NULL;
  while (++k < serv->nb_egg)
    if (serv->egg[k] && serv->egg[k]->team == serv->cli[i]->team
      && (!best || (best->food * 126 + best->life
      > serv->egg[k]->food * 126 + serv->egg[k]->life)))
      {
        best = serv->egg[k];
        nb_best = k;
      }
  if (best == NULL)
    return ;
  send_message_graph(serv, best);
  serv->cli[i]->pos = best->pos;
  serv->cli[i]->life = best->life;
  serv->cli[i]->inventory[6] = best->food;
  remove_egg(serv, nb_best);
}
