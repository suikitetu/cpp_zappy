/*
** io.c for PSU_2016_myirc
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Mon Jun 05 15:11:02 2017 Gauthier Harnisch
** Last update	Mon Jun 26 13:35:50 2017 Gauthier Harnisch
*/

#include "client.h"

int	mread(t_buff *buff, int fd)
{
  int	size;
  char	*buf;

  if (!(buf = (char *)malloc(sizeof(char) * BUFFSIZE)))
    error(84, "malloc failed");
  size = read(fd, buf, SIZE);
  buff_push_front(buff, buf, size);
  free(buf);
  return (size);
}

int	mwrite(t_buff *buff, int fd)
{
  int	size;
  char	*buf;

  buf = buff_get(buff);
  size = write(fd, buf, buff->nb_el);
  buff_move_end(buff, size);
  free(buf);
  return (size);
}

void	fill_arg(fd_set *readfd, fd_set *writefd,
  struct timeval *timeout, struct timespec *last)
{
  struct timespec now;

  clock_gettime(CLOCK_MONOTONIC, &now);
  timeout->tv_sec = 0;
  timeout->tv_usec = timeout->tv_usec -
  ((now.tv_nsec - last->tv_nsec) / 1000) % timeout->tv_usec;
  timeout->tv_usec = timeout->tv_usec * (timeout->tv_usec >= 0);
  timeout->tv_sec = timeout->tv_sec * (timeout->tv_sec >= 0);
  FD_ZERO(readfd);
  FD_ZERO(writefd);
}

void	handle_fd(t_client *client, fd_set *readfd, fd_set *writefd)
{
  if (FD_ISSET(client->fd, writefd))
    mwrite(client->write, client->fd);
  if (FD_ISSET(client->fd, readfd))
    mread(client->read, client->fd);
}

int	wait_select(t_client *client, double wait)
{
  fd_set	readfd;
  fd_set	writefd;
  int	ret;
  struct timespec last;
  struct timeval timeout;

  clock_gettime(CLOCK_MONOTONIC, &last);
  while (1)
    {
      timeout.tv_sec = 0;
      timeout.tv_usec = (int)wait;
      fill_arg(&readfd, &writefd, &timeout, &last);
      FD_SET(client->fd, &readfd);
      FD_SET(client->fd, &writefd);
      ret = select(6, &readfd, &writefd, NULL, &timeout);
      if (ret == -1)
        error(84, "select failed");
      else if (ret)
        handle_fd(client, &readfd, &writefd);
      else
        return (client->read->nb_el + client->write->nb_el);
    }
}
