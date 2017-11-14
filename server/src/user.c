/*
** user.c for PSU_2016_myirc
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Tue May 30 16:33:46 2017 Gauthier Harnisch
** Last update	Sun Jul 02 22:33:52 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	init_client(t_serv *serv, int i)
{
  int	j;

  j = -1;
  serv->cli[i]->fd = serv->net.client_fd;
  serv->cli[i]->team = NULL;
  serv->cli[i]->read = new_buff(BUFFSIZE);
  serv->cli[i]->write = new_buff(BUFFSIZE);
  serv->cli[i]->cycle_to_exec = -1;
  serv->cli[i]->pos = &(serv->map[rand() % serv->sizex][rand() % serv->sizey]);
  serv->cli[i]->flag = 0;
  serv->cli[i]->expect = logg;
  serv->cli[i]->level = 1;
  serv->cli[i]->dir = 1;
  serv->cli[i]->incanting_end = 0;
  serv->cli[i]->life = 126;
  while (++j < 6)
    serv->cli[i]->inventory[j] = 0;
  serv->cli[i]->inventory[6] = 10;
}

void	add_client(t_serv *serv)
{
  static int	next_id = 0;
  int	i;

  if ((serv->net.client_fd = accept(serv->net.fd,
     (struct sockaddr *)&serv->net.s_in_client, &serv->net.s_in_size)) == -1)
    error(84, "accept failed");
  i = 0;
  while (i <= serv->nb_cli && serv->cli[i] != NULL)
    i++;
  if (!(serv->cli[i] = (t_cli *)malloc(sizeof(t_cli))))
    error(84, "malloc failed");
  init_client(serv, i);
  serv->cli[i]->id = next_id++;
  printf("new user:%i\n", serv->cli[i]->id);
  send_cli(serv->cli[i], (char*)"WELCOME\n");
  if (i < serv->nb_cli)
    return ;
  serv->nb_cli++;
  if (!(serv->cli = (t_cli **)realloc(serv->cli, sizeof(t_cli *)
  * (serv->nb_cli + 1))))
    error(84, "realloc failed");
  serv->cli[serv->nb_cli] = NULL;
}

int	remove_client(t_serv *serv, int k)
{
  int	o;

  if (k > serv->nb_cli || serv->cli[k] == NULL)
    return (error(0, "attempt of removing a non-existing client\n"));
  printf("end user:%i\n", serv->cli[k]->id);
  if ((serv->cli[k]->flag & AI) == AI)
    {
      send_cli(serv->cli[k], (char *)"dead\n");
      pdi(serv, k);
    }
  if (serv->cli[k]->team)
    {
      o = -1;
      while (++o < serv->cli[k]->team->nb_user)
        if (serv->cli[k]->team->user[o] == serv->cli[k])
          serv->cli[k]->team->user[o] = NULL;
    }
  if (close(serv->cli[k]->fd) == -1)
    error(84, "close failed in remove_client");
  del_buff(serv->cli[k]->read);
  del_buff(serv->cli[k]->write);
  free(serv->cli[k]);
  serv->cli[k] = NULL;
  return (0);
}
