/*
** print_ressources.c for  in /home/tachet_b/Epitech-projects/PSU_reseaux/PSU_2016_zappy/src/cmd
**
** Made by Benoit Tachet
** Login   <tachet_b@epitech.net>
**
** Started on  Fri Jun 23 10:13:22 2017 Benoit Tachet
** Last update	Sun Jul 02 10:38:03 2017 Gauthier Harnisch
*/

#include "zappy.h"

static void	print_players(t_serv *serv, t_map *pos, t_cli *cli)
{
  int	i;

  i = 0;
  while (i < serv->nb_cli)
    {
      if (serv->cli[i] && serv->cli[i]->pos->x == pos->x &&
	  serv->cli[i]->pos->y == pos->y &&
	  (serv->cli[i]->flag & AI) == AI)
	{
	  send_cli(cli, " player");
	}
      i++;
    }
}

void	print_ressources(t_serv *serv, t_map *pos, t_cli *cli)
{
  int	i;

  print_players(serv, pos, cli);
  i = pos->ressources[0];
  while (i-- > 0)
    send_cli(cli, (char *)" linemate");
  i = pos->ressources[1];
  while (i-- > 0)
    send_cli(cli, (char *)" deraumere");
  i = pos->ressources[2];
  while (i-- > 0)
    send_cli(cli, (char *)" sibur");
  i = pos->ressources[3];
  while (i-- > 0)
    send_cli(cli, (char *)" mendiane");
  i = pos->ressources[4];
  while (i-- > 0)
    send_cli(cli, (char *)" phiras");
  i = pos->ressources[5];
  while (i-- > 0)
    send_cli(cli, (char *)" thystame");
  i = pos->ressources[6];
  while (i-- > 0)
    send_cli(cli, (char *)" food");
}
