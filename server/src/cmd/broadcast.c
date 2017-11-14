/*
** broadcast.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Wed Jun 21 11:39:41 2017 Sébastien Blineau
** Last update	Sun Jul 02 16:45:00 2017 Gauthier Harnisch
*/

#include "zappy.h"

static int	broadcast_dir(int dist_x, int dist_y)
{
  if (dist_y > 0 && ABS(dist_x) * 2 < dist_y)
    return (1);
  if (dist_x > 0 && ABS(dist_y) * 2 < dist_x)
    return (3);
  if (dist_y < 0 && ABS(dist_x) * 2 < -dist_y)
    return (5);
  if (dist_x < 0 && ABS(dist_y) * 2 < -dist_x)
    return (7);
  if (dist_x > 0 && dist_y > 0)
    return (2);
  if (dist_x > 0 && dist_y < 0)
    return (4);
  if (dist_x < 0 && dist_y < 0)
    return (6);
  if (dist_x < 0 && dist_y > 0)
    return (8);
  return (0);
}

static void	broadcast_combine(int to, int from, t_cli *cli)
{
  char	c[2];

  from = (from != 0) * ((from + ((to - 1) * 2) - 1) % 8 + 1);
  c[0] = from + '0';
  c[1] = 0;
  send_cli(cli, (char *)&c);
}

static void	send_message_graph(t_serv *serv, int i, char *msg)
{
  char	*graph_message;

  if ((graph_message = (char *)malloc(MAXLINE)) == NULL)
    error(84, "Malloc failed\n");
  sprintf(graph_message, "pbc %d %s\n", i, msg);
  send_graph(serv, graph_message);
  free(graph_message);
}

void	broadcast(t_serv *serv, int i, char **tab)
{
  int	dist_x;
  int	dist_y;
  int	k;

  k = -1;
  (void)tab;
  while (++k < serv->nb_cli)
    if (serv->cli[k] && i != k && (serv->cli[k]->flag & GRAPHIC) != GRAPHIC)
      {
        dist_x = serv->cli[k]->pos->x - serv->cli[i]->pos->x;
        dist_y = serv->cli[k]->pos->y - serv->cli[i]->pos->y;
        if (ABS(dist_y) > serv->sizey / 2)
          dist_y = -dist_y;
        if (ABS(dist_x) > serv->sizex / 2)
          dist_x = -dist_x;
        send_cli(serv->cli[k], (char *)"message ");
        broadcast_combine(serv->cli[k]->dir,
          broadcast_dir(dist_x, dist_y), serv->cli[k]);
        send_cli(serv->cli[k], (char *)", ");
        send_cli(serv->cli[k], serv->cli[i]->msg + 10);
        send_cli(serv->cli[k], (char *)"\n");
      }
  send_cli(serv->cli[i], (char *)"ok\n");
  send_message_graph(serv, i, serv->cli[i]->msg + 10);
}
