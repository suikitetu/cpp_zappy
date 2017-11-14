/*
** level1-5.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Wed Jun 21 11:39:41 2017 Sébastien Blineau
** Last update	Sun Jul 02 21:20:10 2017 Gauthier Harnisch
*/

#include "zappy.h"

void		level1(t_serv *serv, int i)
{
  if (serv->cli[i]->incanting_end == 0)
    serv->cli[i]->incanting_end = serv->turn + 300;
  else
    serv->cli[i]->incanting_end = 0;
  if (!(serv->cli[i]->pos->ressources[LINEMMATE] == 1 &&
	serv->cli[i]->pos->ressources[DERAUMERE] == 0 &&
	serv->cli[i]->pos->ressources[SIBUR] == 0 &&
	serv->cli[i]->pos->ressources[MENDIANE] == 0 &&
	serv->cli[i]->pos->ressources[PHIRAS] == 0 &&
	serv->cli[i]->pos->ressources[THYSTAME] == 0 &&
	serv->cli[i]->pos->ressources[FOOD] == 0 &&
      check_nummap(serv, i) == 1))
    {
      send_cli(serv->cli[i], "ko\n");
      return ;
    }
  if (serv->cli[i]->incanting_end == 0)
    levelup(serv, i);
  else
    incantation_message(serv->cli[i]);
}

void		level2(t_serv *serv, int i)
{
  if (serv->cli[i]->incanting_end == 0)
    serv->cli[i]->incanting_end = serv->turn + 300;
  else
    serv->cli[i]->incanting_end = 0;
  if (!(serv->cli[i]->pos->ressources[LINEMMATE] == 2 &&
	serv->cli[i]->pos->ressources[DERAUMERE] == 1 &&
	serv->cli[i]->pos->ressources[SIBUR] == 1 &&
	serv->cli[i]->pos->ressources[MENDIANE] == 1 &&
	serv->cli[i]->pos->ressources[PHIRAS] == 0 &&
	serv->cli[i]->pos->ressources[THYSTAME] == 0 &&
	serv->cli[i]->pos->ressources[FOOD] == 0 &&
      check_nummap(serv, i) == 2))
    {
      send_cli(serv->cli[i], "ko\n");
      return ;
    }
  if (serv->cli[i]->incanting_end == 0)
    levelup(serv, i);
  else
    incantation_message(serv->cli[i]);
}

void		level3(t_serv *serv, int i)
{
  if (serv->cli[i]->incanting_end == 0)
    serv->cli[i]->incanting_end = serv->turn + 300;
  else
    serv->cli[i]->incanting_end = 0;
  if (!(serv->cli[i]->pos->ressources[LINEMMATE] == 2 &&
	serv->cli[i]->pos->ressources[DERAUMERE] == 0 &&
	serv->cli[i]->pos->ressources[SIBUR] == 1 &&
	serv->cli[i]->pos->ressources[MENDIANE] == 0 &&
	serv->cli[i]->pos->ressources[PHIRAS] == 2 &&
	serv->cli[i]->pos->ressources[THYSTAME] == 0 &&
	serv->cli[i]->pos->ressources[FOOD] == 0 &&
      check_nummap(serv, i) == 2))
    {
      send_cli(serv->cli[i], "ko\n");
      return ;
    }
  if (serv->cli[i]->incanting_end == 0)
    levelup(serv, i);
  else
    incantation_message(serv->cli[i]);
}

void		level4(t_serv *serv, int i)
{
  if (serv->cli[i]->incanting_end == 0)
    serv->cli[i]->incanting_end = serv->turn + 300;
  else
    serv->cli[i]->incanting_end = 0;
  if (!(serv->cli[i]->pos->ressources[LINEMMATE] == 1 &&
	serv->cli[i]->pos->ressources[DERAUMERE] == 1 &&
	serv->cli[i]->pos->ressources[SIBUR] == 2 &&
	serv->cli[i]->pos->ressources[MENDIANE] == 0 &&
	serv->cli[i]->pos->ressources[PHIRAS] == 1 &&
	serv->cli[i]->pos->ressources[THYSTAME] == 0 &&
	serv->cli[i]->pos->ressources[FOOD] == 0 &&
      check_nummap(serv, i) == 4))
    {
      send_cli(serv->cli[i], "ko\n");
      return ;
    }
  if (serv->cli[i]->incanting_end == 0)
    levelup(serv, i);
  else
    incantation_message(serv->cli[i]);
}

void		level5(t_serv *serv, int i)
{
  if (serv->cli[i]->incanting_end == 0)
    serv->cli[i]->incanting_end = serv->turn + 300;
  else
    serv->cli[i]->incanting_end = 0;
  if (!(serv->cli[i]->pos->ressources[LINEMMATE] == 1 &&
	serv->cli[i]->pos->ressources[DERAUMERE] == 2 &&
	serv->cli[i]->pos->ressources[SIBUR] == 1 &&
	serv->cli[i]->pos->ressources[MENDIANE] == 3 &&
	serv->cli[i]->pos->ressources[PHIRAS] == 0 &&
	serv->cli[i]->pos->ressources[THYSTAME] == 0 &&
	serv->cli[i]->pos->ressources[FOOD] == 0 &&
      check_nummap(serv, i) == 4))
    {
      send_cli(serv->cli[i], "ko\n");
      return ;
    }
  if (serv->cli[i]->incanting_end == 0)
    levelup(serv, i);
  else
    incantation_message(serv->cli[i]);
}
