/*
** fork_graph.c for  in /home/tachet_b/Epitech-projects/PSU_reseaux/PSU_2016_zappy/server/src
** 
** Made by Benoit Tachet
** Login   <tachet_b@epitech.net>
** 
** Started on  Sun Jul  2 13:54:15 2017 Benoit Tachet
** Last update Sun Jul  2 14:06:03 2017 Benoit Tachet
*/

#include "zappy.h"

void	graph_msg_fork(t_serv *serv, int k)
{
  char	*msg;

  if (!(msg = (char *)malloc(MAXLINE)))
    error(84, "failed malloc");
  sprintf(msg, "pfk %d\n", k);
  send_graph(serv, msg);
  free(msg);
}
