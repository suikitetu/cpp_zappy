/*
** team.c for  in /home/harnis_g/rendu/tek2/PSU/PSU_2016_myirc/src/
**
** Made by Gauthier Harnisch
** Login   <harnis_g@epitech.eu>
**
** Started on  Mon May 29 13:49:10 2017 Gauthier Harnisch
** Last update	Wed Jun 28 15:05:42 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	add_to_team(t_team *team, t_cli *cli)
{
  int	i;

  i = 0;
  cli->team = team;
  i = 0;
  while (i <= team->nb_user && team->user[i] != NULL)
    i++;
  team->user[i] = cli;
  if (i < team->nb_user)
    return ;
  team->nb_user++;
  if (!(team->user = (t_cli **)realloc(team->user, sizeof(t_cli *)
      * (team->nb_user + 1))))
    error(84, "realloc failed");
  team->user[team->nb_user] = NULL;
}

void	leave_team(t_team *team, t_cli *cli)
{
  int	i;

  i = -1;
  while (++i < team->nb_user)
    if (team->user[i] == cli)
      team->user[i] = NULL;
  cli->team = NULL;
}

void	add_team(t_serv *serv, char *name)
{
  int	i;

  i = 0;
  while (i <= serv->nb_team && serv->team[i] != NULL)
    i++;
  if (!(serv->team[i] = (t_team *)malloc(sizeof(t_team))))
    error(84, "malloc failed");
  if (!(serv->team[i]->user = (t_cli **)malloc(sizeof(t_cli *))))
    error(84, "malloc failed");
  serv->team[i]->user[0] = NULL;
  serv->team[i]->nb_user = 0;
  serv->team[i]->name = name;
  serv->team[i]->max_nb_players = serv->nb_cli_per_team;
  serv->team[i]->size_cyclearray = 0;
  serv->team[i]->cycles_to_add_clients = NULL;
  printf("new team:%s\n", name);
  if (i < serv->nb_team)
    return ;
  serv->nb_team++;
  if (!(serv->team = (t_team **)realloc(serv->team, sizeof(t_team *)
  * (serv->nb_team + 1))))
    error(84, "realloc failed");
  serv->team[serv->nb_team] = NULL;
}

int	remove_team(t_serv *serv, int k)
{
  if (k > serv->nb_team || !serv->team[k])
    return (0 * printf("attempt of removing a non-existing team\n"));
  printf("end team:%s\n", serv->team[k]->name);
  free(serv->team[k]->user);
  free(serv->team[k]);
  serv->team[k] = NULL;
  return (0);
}
