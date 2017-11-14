/*
** tna.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy/server/src/cmd/graph
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Mon Jun 26 16:28:33 2017 Sébastien Blineau
** Last update	Wed Jun 28 14:59:43 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	tna(t_serv *serv, int i, char **tab)
{
  char  *str;
  int	n;

  n = 0;
  if (tab != NULL && tab[1] != NULL)
    send_cli(serv->cli[i], (char *)"sbp\n");
  while (n < serv->nb_team)
  {
    if (!(str = (char *)malloc(MAXLINE)))
      error(84, "malloc fail");
    sprintf(str, "tna %s\n", serv->team[n]->name);
    send_cli(serv->cli[i], str);
    free(str);
    n++;
  }
}
