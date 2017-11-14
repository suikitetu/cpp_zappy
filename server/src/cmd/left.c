/*
** Left.c for PSU_2016_zappy
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Wed Jun 21 17:07:42 2017 Gauthier Harnisch
** Last update	Wed Jun 28 15:31:34 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	left(t_serv *serv, int i, char **tab)
{
  char	*graph_msg;

  (void)tab;
  if ((graph_msg = (char *)malloc(MAXLINE)) == NULL)
    error(84, "malloc failed\n");
  serv->cli[i]->dir = (serv->cli[i]->dir + 3) % 4;
  send_cli(serv->cli[i], (char *)("ok\n"));
  sprintf(graph_msg, "ppo %d %d %d %d\n", serv->cli[i]->id
	  , serv->cli[i]->pos->x,
	  serv->cli[i]->pos->y, serv->cli[i]->dir);
  send_graph(serv, graph_msg);
  free(graph_msg);
}
