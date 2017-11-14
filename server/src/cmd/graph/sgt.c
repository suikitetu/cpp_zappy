/*
** sgt.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy/server/src/cmd/graph
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Mon Jun 26 15:52:09 2017 Sébastien Blineau
** Last update	Wed Jun 28 14:59:18 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	sgt(t_serv *serv, int i, char **tab)
{
  char  *str;

  if (tab != NULL && tab[1] != NULL)
    send_cli(serv->cli[i], (char *)"sbp\n");
  else
    {
      if (!(str = (char *)malloc(MAXLINE)))
	error(84, "malloc fail");
      sprintf(str, "sgt %ld\n", serv->us);
      send_cli(serv->cli[i], str);
      free(str);
    }
}

void	sst(t_serv *serv, int i, char **tab)
{
  char  *str;

  if (tab[1] == NULL || is_num(tab[1] + 1) == 1
    || atoi(tab[1]) < 2 || atoi(tab[1]) > 10000)
    send_cli(serv->cli[i], (char*)"sbp\n");
  else
    {
      if (!(str = (char *)malloc(MAXLINE)))
	error(84, "malloc fail");
      serv->us = CYCLE_US / atoi(tab[1]);
      sprintf(str, "sgt %ld\n", serv->us);
      send_cli(serv->cli[i], str);
      free(str);
    }
}
