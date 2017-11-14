/*
** bct.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy/server/src/cmd/graph
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Mon Jun 26 15:02:00 2017 Sébastien Blineau
** Last update	Wed Jun 28 14:57:19 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	bctxy(t_serv *serv, int i, char **tab)
{
  char	*str;
  int	x;
  int	y;

  if (tab[1] == NULL || tab[2] == NULL ||
      atoi(tab[1]) >= serv->sizex || atoi(tab[2]) >= serv->sizey ||
      atoi(tab[1]) < 0 || atoi(tab[2]) < 0 ||
      is_num(tab[1] + 1) == 1 || is_num(tab[2] + 1) == 1)
    send_cli(serv->cli[i], (char *)"sbp\n");
  else
    {
      x = atoi(tab[1]);
      y = atoi(tab[2]);
      if (!(str = (char *)malloc(MAXLINE)))
	error(84, "malloc fail");
      sprintf(str, "bct %d %d %d %d %d %d %d %d %d\n",
	      x, y, serv->map[x][y].ressources[6],
	      serv->map[x][y].ressources[0], serv->map[x][y].ressources[1],
	      serv->map[x][y].ressources[2], serv->map[x][y].ressources[3],
	      serv->map[x][y].ressources[4], serv->map[x][y].ressources[5]);
      send_cli(serv->cli[i], str);
      free(str);
    }
}

void	bctxy_bct(t_serv *serv, int i, int x, int y)
{
  char  *str;

  if (!(str = (char *)malloc(MAXLINE)))
    error(84, "malloc fail");
  sprintf(str, "bct %d %d %d %d %d %d %d %d %d\n",
	  x, y, serv->map[x][y].ressources[6],
	  serv->map[x][y].ressources[0], serv->map[x][y].ressources[1],
	  serv->map[x][y].ressources[2], serv->map[x][y].ressources[3],
	  serv->map[x][y].ressources[4], serv->map[x][y].ressources[5]);
  send_cli(serv->cli[i], str);
  free(str);
}

void	bct(t_serv *serv, int i, char **tab)
{
  int	x;
  int	y;

  y = 0;
  if (tab != NULL && tab[1] != NULL)
    send_cli(serv->cli[i], (char *)"sbp\n");
  else
    {
      while (y < serv->sizey)
	{
	  x = 0;
	  while (x < serv->sizex)
	    {
	      bctxy_bct(serv, i, x, y);
	      x++;
	    }
	  y++;
	}
    }
}
