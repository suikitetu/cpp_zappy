/*
** map_size.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy/server/src/cmd/graph
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Mon Jun 26 14:18:45 2017 Sébastien Blineau
** Last update	Wed Jun 28 14:58:23 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	msz(t_serv *serv, int i, char **tab)
{
  char	*str;

  if (tab != NULL && tab[1] != NULL)
    send_cli(serv->cli[i], (char *)"sbp\n");
  else
    {
      if (!(str = (char *)malloc(MAXLINE)))
	error(84, "malloc fail");
      sprintf(str, "msz %d %d\n", serv->sizex, serv->sizey);
      send_cli(serv->cli[i], str);
      free(str);
    }
}
