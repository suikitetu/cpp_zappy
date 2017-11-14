/*
** Right.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy/src/cmd
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Tue Jun 20 18:04:47 2017 Sébastien Blineau
** Last update	Wed Jun 28 15:31:41 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	right(t_serv *serv, int i, char **tab)
{
  char	*graph_msg;

  (void)tab;
  if ((graph_msg = (char *)malloc(MAXLINE)) == NULL)
    error(84, "Malloc failed\n");
  serv->cli[i]->dir = (serv->cli[i]->dir + 1) % 4;
  send_cli(serv->cli[i], (char *)"ok\n");
  sprintf(graph_msg, "ppo %d %d %d %d\n", serv->cli[i]->id
	  , serv->cli[i]->pos->x,
	  serv->cli[i]->pos->y, serv->cli[i]->dir);
  send_graph(serv, graph_msg);
  free(graph_msg);
}
