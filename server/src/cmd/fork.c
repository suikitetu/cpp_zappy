/*
** Fork.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Wed Jun 21 11:39:41 2017 Sébastien Blineau
** Last update	Fri Jun 30 15:22:10 2017 Gauthier Harnisch
*/

#include "zappy.h"

static void	send_message_graph(t_serv *serv, int i)
{
  char	*msg;

  if ((msg = (char *)malloc(MAXLINE)) == NULL)
    error(84, "malloc failed\n");
  sprintf(msg, "enw %d %d %d %d\n", serv->cli[i]->team->size_cyclearray,
	  serv->cli[i]->id,
	  serv->cli[i]->pos->x, serv->cli[i]->pos->y);
  send_graph(serv, msg);
  free(msg);
}

void	mfork(t_serv *serv, int i, char **tab)
{
  (void)tab;
  new_egg(serv, i);
  send_cli(serv->cli[i], (char *)"ok\n");
  send_message_graph(serv, i);
}
