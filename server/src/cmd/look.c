/*
** Look.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Wed Jun 21 11:39:41 2017 Sébastien Blineau
** Last update	Sun Jul 02 22:59:27 2017 Gauthier Harnisch
*/

#include "zappy.h"

static void	look_up(t_serv *serv, t_cli *cli)
{
  int	n;
  int	m;

  n = 0;
  send_cli(cli, (char *)"[");
  while (n <= cli->level)
    {
      m = -n;
      while (m <= n)
	{
	  print_ressources(serv, &serv->map
      [(cli->pos->x + serv->sizex + m) % serv->sizex]
      [(cli->pos->y + serv->sizey - n) % serv->sizey], cli);
	  if (n < cli->level || m < n)
	    send_cli(cli, (char *)",");
	  m++;
	}
      n++;
    }
  send_cli(cli, (char *)"]\n");
}

static void	look_down(t_serv *serv, t_cli *cli)
{
  int	n;
  int	m;

  n = 0;
  send_cli(cli, (char *)"[");
  while (n <= cli->level)
    {
      m = -n;
      while (m <= n)
	{
	  print_ressources(serv, &serv->map
      [(cli->pos->x + serv->sizex - m) % serv->sizex]
      [(cli->pos->y + serv->sizey + n) % serv->sizey], cli);
	  if (n < cli->level || m < n)
	    send_cli(cli, (char *)",");
	  m++;
	}
      n++;
    }
  send_cli(cli, (char *)"]\n");
}

static void	look_left(t_serv *serv, t_cli *cli)
{
  int	n;
  int	m;

  n = 0;
  send_cli(cli, (char *)"[");
  while (n <= cli->level)
    {
      m = -n;
      while (m <= n)
	{
	  print_ressources(serv, &serv->map
      [(cli->pos->x + serv->sizex - n) % serv->sizex]
      [(cli->pos->y + serv->sizey - m) % serv->sizey], cli);
	  if (n < cli->level || m < n)
	    send_cli(cli, (char *)",");
	  m++;
	}
      n++;
    }
  send_cli(cli, (char *)"]\n");
}

static void	look_right(t_serv *serv, t_cli *cli)
{
  int	n;
  int	m;

  n = 0;
  send_cli(cli, (char *)"[");
  while (n <= cli->level)
    {
      m = -n;
      while (m <= n)
	{
	  print_ressources(serv, &serv->map
      [(cli->pos->x + serv->sizex + n) % serv->sizex]
      [(cli->pos->y + serv->sizey + m) % serv->sizey], cli);
	  if (n < cli->level || m < n)
	    send_cli(cli, (char *)",");
	  m++;
	}
      n++;
    }
  send_cli(cli, (char *)"]\n");
}

void	look(t_serv *serv, int i, char **tab)
{
  (void)tab;
  if (serv->cli[i]->dir % 2 == 0)
    {
      if (serv->cli[i]->dir == 2)
	look_right(serv, serv->cli[i]);
      else
	look_left(serv, serv->cli[i]);
    }
  else
    {
      if (serv->cli[i]->dir == 1)
	look_up(serv, serv->cli[i]);
      else
	look_down(serv, serv->cli[i]);
    }
}
