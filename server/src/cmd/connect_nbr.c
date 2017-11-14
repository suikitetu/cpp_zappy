/*
** Connect_nbr.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Wed Jun 21 11:39:41 2017 Sébastien Blineau
** Last update	Wed Jun 28 15:01:16 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	connect_nbr(t_serv *serv, int i, char **tab)
{
  int	n;
  char	*str;

  (void)tab;
  n = serv->cli[i]->team->max_nb_players - serv->cli[i]->team->nb_user;
  str = itoa(n);
  send_cli(serv->cli[i], str);
  send_cli(serv->cli[i], (char *)"\n");
  free(str);
}
