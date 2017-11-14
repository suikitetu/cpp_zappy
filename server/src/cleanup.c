/*
** cleanup.c for PSU_2016_myftp
**
** Made by	Gauthier Harnisch
** Login	harins_g
**
** Started on	Fri May 12 10:47:48 2017 Gauthier Harnisch
** Last update	Sun Jul 02 18:23:17 2017 Gauthier Harnisch
*/

#include "zappy.h"

extern t_serv	*g_serv;

void	cleanup()
{
  int	i;

  if (g_serv)
    {
      printf("\r%ld:cleaning:\n", g_serv->turn);
      if (close(g_serv->net.fd) == -1)
        error(84, "close server failed in cleanup");
      i = -1;
      while (++i <= g_serv->nb_cli)
        if (g_serv->cli[i])
          remove_client(g_serv, i);
      i = -1;
      while (++i <= g_serv->nb_team)
        if (g_serv->team[i])
          remove_team(g_serv, i);
      del_map(g_serv->map, g_serv->sizex);
      free(g_serv->cli);
      free(g_serv->team);
      free(g_serv->egg);
    }
  g_serv = NULL;
  exit(0);
}
