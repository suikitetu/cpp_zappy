/*
** io.c for PSU_2016_myirc
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Mon Jun 05 15:11:02 2017 Gauthier Harnisch
** Last update	Sun Jul 02 19:17:23 2017 Gauthier Harnisch
*/

#include "zappy.h"

static struct timeval timeout = {0, 10};

extern t_serv	*g_serv;

int	mread(t_buff *buff, int fd)
{
  int	size;
  char	*buf;

  if (!(buf = (char *)malloc(sizeof(char) * BUFFSIZE)))
    return (error(84, "malloc failed"));
  if ((size = read(fd, buf, SIZE)) == -1)
    {
      free(buf);
      return (error(0, "read failed") - 1);
    }
  buff_push_front(buff, buf, size);
  free(buf);
  return (size);
}

int	mwrite(t_buff *buff, int fd)
{
  int	size;
  char	*buf;

  buf = buff_get(buff);

  if ((size = write(fd, buf, buff->nb_el)) == -1)
    {
      free(buf);
      return (error(0, "write error") - 1);
    }
  buff_move_end(buff, size);
  free(buf);
  return (size);
}

int	send_cli(t_cli *cli, char *msg)
{
  fd_set	writefd;
  int	ret;

  if ((cli->flag & DEAD) == DEAD)
    return (-1);
  buff_push_front(cli->write, msg, strlen(msg));
  FD_ZERO(&writefd);
  FD_SET(cli->fd, &writefd);
  if ((ret = select(cli->fd + 1, NULL, &writefd, NULL, &timeout)) == -1)
    error(84, "select failed");
  else if (ret)
    if (mwrite(cli->write, cli->fd) == -1)
      {
        cli->flag = cli->flag | DEAD;
        buff_empty(cli->write);
        return (-1);
      }
  printf("%ld:resp:%i:\"%s\"\n", g_serv->turn, cli->id, msg);
  return (0);
}
