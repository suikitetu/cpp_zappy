/*
** Eject.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Wed Jun 21 11:39:41 2017 Sébastien Blineau
** Last update	Sun Jul 02 22:55:55 2017 Gauthier Harnisch
*/

#include "zappy.h"

static void	send_ex_message(t_serv *serv, int i)
{
  char	*msg;

  if ((msg = (char *)malloc(MAXLINE)) == NULL)
    error(84, "malloc failed\n");
  sprintf(msg, "pex %d\n", serv->cli[i]->id);
  send_graph(serv, msg);
  free(msg);
}

static void	send_message(t_serv *serv, int i, int dir)
{
  char	*msg;
  if ((msg = malloc(255)) == NULL)
    error(84, "malloc failed\n");
  sprintf(msg, "eject: %d\n", dir == 0 ? 4 : dir);
  send_cli(serv->cli[i], msg);
  sprintf(msg, "ppo %d %d %d %d\n", serv->cli[i]->id, serv->cli[i]->pos->x,
	  serv->cli[i]->pos->y, serv->cli[i]->dir);
  send_graph(serv, msg);
  free(msg);
}

static void	move_perso(t_serv *serv, int i, int actual_client)
{
  int	posx;
  int	posy;

  posx = serv->cli[actual_client]->pos->x;
  posy = serv->cli[actual_client]->pos->y;
  if (serv->cli[i] && serv->cli[i]->dir % 2 == 0)
    {
      if (serv->cli[i] && serv->cli[i]->dir == RIGHT)
	serv->cli[actual_client]->pos = &(serv->map[(posx + 1) == serv->sizex ?
						    0 : posx + 1][posy]);
      else
	serv->cli[actual_client]->pos = &(serv->map[(posx - 1) < 0 ? serv->sizex
						    - 1 : posx - 1][posy]);
    }
  else
    {
      if (serv->cli[i] && serv->cli[i]->dir == UP)
	serv->cli[actual_client]->pos = &(serv->map[posx][(posy - 1) < 0 ?
							  serv->sizey - 1 :
							  posy - 1]);
      else
	serv->cli[actual_client]->pos = &(serv->map[posx]
					  [(posy + 1) == serv->sizex ? 0 :
					   posy + 1]);
    }
}

void	eject(t_serv *serv, int i, char **tab)
{
  (void )(tab);
  int	actual_cli;
  int	nb_pushed_clients;

  nb_pushed_clients = 0;
  actual_cli = -1;
  send_ex_message(serv, i);
  while (serv->cli[++actual_cli])
    if (serv->cli[i] && serv->cli[actual_cli]->pos == serv->cli[i]->pos	&& actual_cli != i)
      {
	move_perso(serv, i, actual_cli);
	if (serv->cli[i] && serv->cli[i]->dir % 2 == 0)
	  send_message(serv, actual_cli,
		       serv->cli[i]->dir == RIGHT ? LEFT : RIGHT);
	else
	  send_message(serv, actual_cli,
		       serv->cli[i]->dir == UP ? DOWN : UP);
	nb_pushed_clients++;
      }
  if (nb_pushed_clients != 0)
    send_cli(serv->cli[i], (char *)"ok\n");
  else
    send_cli(serv->cli[i], (char *)"ko\n");
}
