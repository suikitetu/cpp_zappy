/*
** io.c for PSU_2016_zappy
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Mon Jun 26 11:13:55 2017 Gauthier Harnisch
** Last update	Sun Jul 02 15:29:48 2017 Gauthier Harnisch
*/

#include "client.h"

static t_client *target = NULL;
struct timeval timeout = {0, 10};

void	set_target(t_client *cli)
{
  target = cli;
}

void	set_timeout(long usec)
{
  timeout.tv_sec = 0;
  timeout.tv_usec = usec;
}

int	msend(char *msg)
{
  fd_set	writefd;
  int	ret;

  buff_push_front(target->write, msg, strlen(msg));
  FD_ZERO(&writefd);
  FD_SET(target->fd, &writefd);
  if ((ret = select(target->fd + 1, NULL, &writefd, NULL, &timeout)) == -1)
    error(84, "select failed");
  else if (ret)
    {
      if ((ret = mwrite(target->write, target->fd)) <= 0)
        error(84, "server disconected");
      else
        return (ret);
    }
  return (0);
}

char	*mrecv()
{
  fd_set	readfd;
  int	ret;

  FD_ZERO(&readfd);
  FD_SET(target->fd, &readfd);
  if ((ret = select(target->fd + 1, &readfd, NULL, NULL, &timeout)) == -1)
    error(84, "select failed");
  else if (ret)
    mread(target->read, target->fd);
  return (buff_pop_line(target->read));
}

char	*mblock_recv()
{
  fd_set	readfd;
  int	ret;
  char	*res;

  while (!(res = buff_pop_line(target->read)))
    {
      FD_ZERO(&readfd);
      FD_SET(target->fd, &readfd);
      if ((ret = select(target->fd + 1, &readfd, NULL, NULL, &timeout)) == -1)
        error(84, "select failed");
      else if (ret)
        if (mread(target->read, target->fd) <= 0)
          error(84, "server disconected");
    }
  return (res);
}
