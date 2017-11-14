/*
** select_read.c for  in /home/harnis_g/rendu/tek2/PSU/PSU_2016_myirc/src/
**
** Made by Gauthier Harnisch
** Login   <harnis_g@epitech.eu>
**
** Started on  Mon May 29 13:49:21 2017 Gauthier Harnisch
** Last update	Sun Jul 02 19:18:28 2017 Gauthier Harnisch
*/

#include "zappy.h"

static int	read_user(t_serv *serv, int i)
{
  if (mread(serv->cli[i]->read, serv->cli[i]->fd) <= 0)
    {
      error(0, "client diconected");
      serv->cli[i]->flag |= DEAD;
      return (remove_client(serv, i));
    }
  return (pop_cmd(serv, i));
}

static void	fill_fd(t_serv *serv, fd_set *readfd, fd_set *writefd)
{
  int	i;

  FD_ZERO(readfd);
  FD_ZERO(writefd);
  FD_SET(serv->net.fd, readfd);
  i = -1;
  while (++i < serv->nb_cli)
    if (serv->cli[i] && (serv->cli[i]->flag & DEAD) != DEAD)
      FD_SET(serv->cli[i]->fd, readfd);
  i = -1;
  while (++i < serv->nb_cli)
    if (serv->cli[i] && serv->cli[i]->write->nb_el > 0
      && (serv->cli[i]->flag & DEAD) != DEAD)
      FD_SET(serv->cli[i]->fd, writefd);
}

static void	call_handle(t_serv *serv, fd_set *readfd, fd_set *writefd)
{
  int	i;

  i = -1;
  while (++i < serv->nb_cli)
    if (serv->cli[i] && FD_ISSET(serv->cli[i]->fd, readfd))
      read_user(serv, i);
  i = -1;
  while (++i < serv->nb_cli)
    if (serv->cli[i] && FD_ISSET(serv->cli[i]->fd, writefd))
      if (mwrite(serv->cli[i]->write, serv->cli[i]->fd) == -1)
        remove_client(serv, i);
  if (FD_ISSET(serv->net.fd, readfd))
    add_client(serv);
}

void	wait_select(t_serv *serv)
{
  fd_set	readfd;
  fd_set	writefd;
  int	ret;
  struct timespec now;
  struct timeval timeout;

  fill_fd(serv, &readfd, &writefd);
  clock_gettime(CLOCK_MONOTONIC, &now);
  timeout.tv_sec = 0;
  timeout.tv_usec = (serv->us - ((now.tv_sec - serv->last.tv_sec) * CYCLE_US
  + (now.tv_nsec - serv->last.tv_nsec) / 1000));
  timeout.tv_usec = timeout.tv_usec * (timeout.tv_usec >= 0);
  ret = select(serv->nb_cli + 4, &readfd, &writefd, NULL, &timeout);
  if (ret == -1)
    error(84, "select failed");
  else if (ret)
    call_handle(serv, &readfd, &writefd);
  else
    cycle(serv);
}
