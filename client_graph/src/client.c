/*
** client.c for  in /home/mag_d/rendu/PSU_2016_zappy/client_src
**
** Made by david mag
** Login   <mag_d@epitech.net>
**
** Started on  Thu Jun 22 12:31:24 2017 david mag
** Last update	Sun Jul 02 13:23:43 2017 Gauthier Harnisch
*/

#include "client.h"

void	set_cli(t_client *c)
{
  if (c->fd == -1)
    error(84, "socket failed");
  c->s_in.sin_family = AF_INET;
  c->s_in.sin_port = htons(c->port);
  c->s_in.sin_addr.s_addr = inet_addr(c->ip);
  if (connect(c->fd, (struct sockaddr *)&c->s_in, sizeof(c->s_in)) == -1)
    {
      error(0, "connect failed");
      if (close(c->fd) == -1)
        error(84, "close failed");
      exit(84);
    }
  c->write = new_buff(BUFFSIZE);
  c->read = new_buff(BUFFSIZE);
}

void	end_co(t_client *c)
{
  if (close(c->fd) == -1)
    error(84, "close failed");
  del_buff(c->write);
  del_buff(c->read);
}

void	client(t_client *c)
{
  c->pe = getprotobyname("TCP");
  if (!c->pe)
    error(84, "getprotobyname failed");
  if ((c->fd = socket(AF_INET, SOCK_STREAM, c->pe->p_proto)) == -1)
    error(84, "socket failed");
  set_cli(c);
  set_target(c);
  set_timeout(1);
}
