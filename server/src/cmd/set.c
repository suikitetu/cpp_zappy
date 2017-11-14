/*
** Take.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Wed Jun 21 11:39:41 2017 Sébastien Blineau
** Last update	Sun Jul 02 22:49:30 2017 Gauthier Harnisch
*/

#include "zappy.h"

static void	send_graphic(t_serv *serv, int i, int ressource)
{
  char	*str;

  if ((str = (char *)malloc(MAXLINE)) == NULL)
    error(84, "Malloc failed\n");
  sprintf(str, "pdr %d %d\n", serv->cli[i]->id, (ressource + 1) % 7);
  send_graph(serv, str);
  sprintf(str, "pin %i %i %i %i %i %i %i\n",
  serv->cli[i]->inventory[6], serv->cli[i]->inventory[0],
  serv->cli[i]->inventory[1], serv->cli[i]->inventory[2],
  serv->cli[i]->inventory[3], serv->cli[i]->inventory[4],
  serv->cli[i]->inventory[5]);
  send_graph(serv, str);
  sprintf(str, "bct %i %i %i %i %i %i %i %i %i\n", serv->cli[i]->pos->x,
  serv->cli[i]->pos->y,
  serv->map[serv->cli[i]->pos->x][serv->cli[i]->pos->y].ressources[6],
  serv->map[serv->cli[i]->pos->x][serv->cli[i]->pos->y].ressources[0],
  serv->map[serv->cli[i]->pos->x][serv->cli[i]->pos->y].ressources[1],
  serv->map[serv->cli[i]->pos->x][serv->cli[i]->pos->y].ressources[2],
  serv->map[serv->cli[i]->pos->x][serv->cli[i]->pos->y].ressources[3],
  serv->map[serv->cli[i]->pos->x][serv->cli[i]->pos->y].ressources[4],
  serv->map[serv->cli[i]->pos->x][serv->cli[i]->pos->y].ressources[5]);
  send_graph(serv, str);
  free(str);
}

static const char	*ressources[] =
{
  " linemate",
  " deraumere",
  " sibur",
  " mendiane",
  " phiras",
  " thystame",
  " food"
};

void	set(t_serv *serv, int i, char **tab)
{
  int	j;

  j = -1;
  while (++j < 7)
    if (match(tab[1], ressources[j]) && serv->cli[i]->inventory[j] > 0)
      {
        serv->cli[i]->inventory[j] -= 1;
        serv->cli[i]->pos->ressources[j] += 1;
        send_cli(serv->cli[i], (char *)"ok\n");
        send_graphic(serv, i, j);
        return ;
      }
  send_cli(serv->cli[i], (char *)"ko\n");
}
