/*
** Forward.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy/src/cmd
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Tue Jun 20 16:21:00 2017 Sébastien Blineau
** Last update	Wed Jun 28 15:18:04 2017 Gauthier Harnisch
*/

#include "zappy.h"

static void	send_message_graphic(t_serv *serv, int i)
{
  char	*graph_msg;

  if ((graph_msg = (char *)malloc(MAXLINE)) == NULL)
    error(84, "malloc failed\n");
  sprintf(graph_msg, "ppo %d %d %d %d\n", serv->cli[i]->id,
	  serv->cli[i]->pos->x,
	  serv->cli[i]->pos->y, serv->cli[i]->dir);
  send_graph(serv, graph_msg);
  free(graph_msg);
}

static void	forward_hori(t_serv *serv, int i, int posx, int posy)
{
      if (serv->cli[i]->dir == RIGHT)
	serv->cli[i]->pos = &(serv->map[posx + 1 >= serv->sizex ? 0 :
					posx + 1][posy]);
      else
	serv->cli[i]->pos = &(serv->map[posx - 1 < 0 ? serv->sizex - 1 :
					posx - 1][posy]);
}

void	forward(t_serv *serv, int i, char **tab)
{
  (void)tab;
  int	posx;
  int	posy;

  posx = serv->cli[i]->pos->x;
  posy = serv->cli[i]->pos->y;
  if ((serv->cli[i]->dir % 2) == 0)
    {
      forward_hori(serv, i, posx, posy);
    }
  else
    {
      if (serv->cli[i]->dir == UP)
	serv->cli[i]->pos = &(serv->map[posx]
			      [posy - 1 < 0 ? serv->sizey - 1 : posy - 1]);
      else
	serv->cli[i]->pos = &(serv->map[posx]
			      [posy + 1 >= serv->sizey ? 0 : posy + 1]);
    }
  send_cli(serv->cli[i], (char *)"ok\n");
  send_message_graphic(serv, i);
}
