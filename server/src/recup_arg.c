/*
** recup_arg.c for PSU_2016_zappy
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Wed Jun 28 16:42:44 2017 Gauthier Harnisch
** Last update	Fri Jun 30 11:28:25 2017 Gauthier Harnisch
*/

#include "zappy.h"

int	is_num(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] < 48 || str[i] > 57)
	return (1);
      i++;
    }
  return (0);
}

int	create_teams(t_serv *serv, int ac, char **av, int i)
{
  int	a;

  a = i;
  serv->boool = 1;
  while (a + 1 < ac && av[a + 1][0] != '-')
    {
      if (cmp_team(av[a + 1], serv) >= 0 || strcmp(av[a + 1], "GRAPHIC") == 0)
	{
	  error(84, "-n option only accepts unique team names \
(name : \"GRAPHIC\" is not valid)");
	}
      add_team(serv, av[a + 1]);
      a++;
    }
  i = a - 1;
  return (i);
}

int	arg_again(t_serv *serv, int ac, char **av, int i)
{
  if (av[i][0] == '-' && strlen(av[i]) == 2 && av[i][1] == 'x')
    {
      if (i + 1 >= ac || is_num(av[i + 1]) == 1 ||
	  atoi(av[i + 1]) < 10)
	{
	  error(84, "-x option only accepts integer values bigger than 10");
	}
      else
	serv->sizex = atoi(av[i + 1]);
    }
  if (av[i][0] == '-' && strlen(av[i]) == 2 && av[i][1] == 'n')
    {
      if (i + 1 >= ac || av[i + 1][0] == '-')
	{
	  error(84, "-n option requires an argument");
	}
      else
	i = create_teams(serv, ac, av, i);
    }
  return (i);
}

int	other_arg(t_serv *serv, int ac, char **av, int i)
{
  int	f;

  f = 2;
  if (av[i][0] == '-' && strlen(av[i]) == 2 && av[i][1] == 'y')
    if (i + 1 >= ac || is_num(av[i + 1]) == 1 ||
	atoi(av[i + 1]) < 10)
      error(84, "-y option only accepts integer values bigger than 10");
    else
      serv->sizey = atoi(av[i + 1]);
  else if (av[i][0] == '-' && strlen(av[i]) == 2 && av[i][1] == 'c')
    if (i + 1 >= ac || is_num(av[i + 1]) == 1 || atoi(av[i + 1]) < 1)
      error(84, "-c option only accepts integer values greater or equal to 1");
    else
      serv->nb_cli_per_team = atoi(av[i + 1]);
  else if (av[i][0] == '-' && strlen(av[i]) == 2 && av[i][1] == 'f')
   {
      if (i + 1 >= ac || is_num(av[i + 1]) == 1 ||
	  atoi(av[i + 1]) < 2 || atoi(av[i + 1]) > 10000)
	error(84, "-f option only accepts integer values between 2 and 10000");
      else
	f = atoi(av[i + 1]);
    }
  return (f);
}

int	recup_arg(t_serv *serv, int ac, char **av)
{
  int   i;
  int   port;
  int	f;

  i = 1;
  f = 2;
  port = 4242;
  serv->us = CYCLE_US / f;
  while (i < ac)
    {
      if (av[i][0] != '-')
	return (port);
      else if (av[i][0] == '-' && strlen(av[i]) == 2 && av[i][1] == 'p')
	{
	  if (i + 1 >= ac || is_num(av[i + 1]) == 1)
	    error(84, "-p option only accepts valid ports");
	  else
	    port = atoi(av[i + 1]);
	}
      f = other_arg(serv, ac, av, i);
      i = arg_again(serv, ac, av, i);
      i += 2;
      serv->us = CYCLE_US / f;
    }
  return (port);
}
