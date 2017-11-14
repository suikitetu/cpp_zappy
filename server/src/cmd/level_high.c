/*
** level1-5.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Wed Jun 21 11:39:41 2017 Sébastien Blineau
** Last update	Sun Jul 02 20:29:03 2017 Gauthier Harnisch
*/

#include "zappy.h"

void		level6(t_serv *serv, int i)
{
  if (serv->cli[i]->incanting_end == 0)
    serv->cli[i]->incanting_end = serv->turn + 300;
  else
    serv->cli[i]->incanting_end = 0;
  if (!(serv->cli[i]->pos->ressources[LINEMMATE] == 1 &&
	serv->cli[i]->pos->ressources[DERAUMERE] == 2 &&
	serv->cli[i]->pos->ressources[SIBUR] == 3 &&
	serv->cli[i]->pos->ressources[MENDIANE] == 0 &&
	serv->cli[i]->pos->ressources[PHIRAS] == 1 &&
	serv->cli[i]->pos->ressources[THYSTAME] == 0 &&
	serv->cli[i]->pos->ressources[FOOD] == 0) &&
      check_nummap(serv, i) == 6)
    {
      send_cli(serv->cli[i], (char *)"ko\n");
      return ;
    }
  if (serv->cli[i]->incanting_end == 0)
    levelup(serv, i);
  else
    incantation_message(serv->cli[i]);

}

void		level7(t_serv *serv, int i)
{
  if (serv->cli[i]->incanting_end == 0)
    serv->cli[i]->incanting_end = serv->turn + 300;
  else
    serv->cli[i]->incanting_end = 0;
  if (!(serv->cli[i]->pos->ressources[LINEMMATE] == 2 &&
	serv->cli[i]->pos->ressources[DERAUMERE] == 2 &&
	serv->cli[i]->pos->ressources[SIBUR] == 2 &&
	serv->cli[i]->pos->ressources[MENDIANE] == 2 &&
	serv->cli[i]->pos->ressources[PHIRAS] == 2 &&
	serv->cli[i]->pos->ressources[THYSTAME] == 1 &&
	serv->cli[i]->pos->ressources[FOOD] == 0) &&
      check_nummap(serv, i) == 6)
    {
      send_cli(serv->cli[i], "ko\n");
      return ;
    }
  if (serv->cli[i]->incanting_end == 0)
    levelup(serv, i);
  else
    incantation_message(serv->cli[i]);
}

void		level8(t_serv *serv, int i)
{
  (void)serv;
  (void)i;
  send_cli(serv->cli[i], "ko\n");
}

void	incantation_message(t_cli *cli)
{
  char	*msg;

  if ((msg = (char *)malloc(MAXLINE)) == NULL)
    error(84, "Malloc failed");
  sprintf(msg, "Elevation underway\n");
  send_cli(cli, msg);
  free(msg);
}
