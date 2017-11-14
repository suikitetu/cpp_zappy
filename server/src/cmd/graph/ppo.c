/*
** tna.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy/server/src/cmd/graph
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Mon Jun 26 16:28:33 2017 Sébastien Blineau
** Last update	Wed Jun 28 15:01:01 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	ppo(t_serv *serv, int i, char **tab)
{
  char	*str;

  (void)tab;
  if (!(str = (char *)malloc(sizeof(char) * MAXLINE)))
    error(84, "malloc failed");
  sprintf(str, "ppo %d %d %d %d\n", i, serv->cli[i]->pos->x,
	  serv->cli[i]->pos->y, serv->cli[i]->dir);
  send_cli(serv->cli[i], str);
  free(str);
}
