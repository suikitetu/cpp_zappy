/*
** cycle.c for PSU_2016_zappy
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Tue Jun 20 17:14:01 2017 Gauthier Harnisch
** Last update	Sun Jul 02 22:36:51 2017 Gauthier Harnisch
*/

#include "zappy.h"

int	get_nb_to_rm(long *tab, int tabsize, int val)
{
  int	i;
  int	nbval;

  i = 0;
  nbval = 0;
  while (i < tabsize)
    {
      if (tab[tabsize] <= val)
	nbval++;
      i++;
    }
  return (nbval);
}

void	remove_timer_from_teamarray(t_team *team, int value)
{
  long	*newarray;
  int	i;
  int	nb_to_rm;
  int	j;

  nb_to_rm = get_nb_to_rm(team->cycles_to_add_clients, team->size_cyclearray,
			  value);
  if (!(newarray = (long *)malloc(sizeof(team->cycles_to_add_clients)
  - (sizeof(long) * nb_to_rm))))
    error(84, "malloc failed");
  i = j = 0;
  while (i < team->size_cyclearray)
    {
      if (team->cycles_to_add_clients[i] > value)
	{
	  newarray[j] = team->cycles_to_add_clients[i];
	  j++;
	}
      i++;
    }
  free(team->cycles_to_add_clients);
  team->cycles_to_add_clients = newarray;
}

static void	print_msg_graphic(t_serv *serv, int i)
{
  char	*msg;

  if ((msg = (char *)malloc(MAXLINE)) == NULL)
    error(84, "malloc failed\n");
  sprintf(msg, "eht %lu\n", sizeof(serv->team[i]->cycles_to_add_clients)
   / sizeof(long));
  send_graph(serv, msg);
  free(msg);
}

static void	check_new_clients_team(t_serv *serv)
{
  int	i;
  int	j;

  i = 0;
  while (i < serv->nb_team)
    {
      if (serv->team[i])
	{
	  j = 0;
	  while (j < serv->team[i]->size_cyclearray)
	    {
	      if (serv->turn >= serv->team[i]->cycles_to_add_clients[j])
		{
		  serv->team[i]->max_nb_players++;
		  remove_timer_from_teamarray(serv->team[i], serv->turn);
		  print_msg_graphic(serv, i);
		}
	      j++;
	    }
	  j = 0;
	}
      i++;
    }
  check_egg(serv);
}

void	cycle(t_serv *serv)
{
  int	i;

  clock_gettime(CLOCK_MONOTONIC, &serv->last);
  serv->turn++;
  check_new_clients_team(serv);
  i = -1;
  // write(1, "", 0);
  while (++i < serv->nb_cli)
      {
        if (serv->cli[i] && (serv->cli[i]->flag & DEAD) == DEAD)
          remove_client(serv, i);
        if (serv->cli[i] && serv->cli[i]->cycle_to_exec == serv->turn)
          exec_cmd(serv, i);
        if (serv->cli[i] && serv->cli[i]->incanting_end == serv->turn)
          incantation(serv, i, NULL);
        if (serv->cli[i] && serv->cli[i]->flag == AI)
          death(serv, i);
      }
  i = -1;
  while (++i < serv->nb_egg)
    if (serv->egg[i])
  	 death_egg(serv, i);
}
