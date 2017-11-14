/*
** cmd_example.c for PSU_2016_zappy
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Tue Jun 20 15:46:15 2017 Gauthier Harnisch
** Last update	Wed Jun 21 17:41:19 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	cmd_example(t_serv *serv, int i, char **tab)
{
  (void)tab;
  send_cli(serv->cli[i], (char *)"this is an example\n");
}
