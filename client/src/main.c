/*
** main.c for main in /home/mag_d/rendu/PSU_2016_zappy/client_src
**
** Made by david mag
** Login   <mag_d@epitech.net>
**
** Started on  Wed Jun 21 17:01:13 2017 david mag
** Last update	Thu Jun 29 14:52:37 2017 Gauthier Harnisch
*/

#include "client.h"

void		help()
{
  printf("USAGE: ./zappy_ai -p port -n name -h machine\n");
  printf("\tport\tis the port number\n");
  printf("\tname\tis the name of the team\n");
  printf("\tmachine\tis the name of the machine; localhost by default\n");
}

bool		isnum(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (false);
      i++;
    }
  return (true);
}

void		pars(int ac, char **av)
{
  int		i;
  t_client	*c;

  if ((c = (t_client*)malloc(sizeof(t_client))) == NULL)
    return ;
  c->port = 0;
  c->team_name = NULL;
  c->ip = NULL;
  i = 1;
  while (i < ac)
    {
      if (strcmp("-p", av[i]) == 0 && i + 1 < ac && isnum(av[i + 1]) == true)
  	c->port = atoi(av[i + 1]);
      if (strcmp("-h", av[i]) == 0 && i + 1 < ac)
  	c->ip = strdup(av[i + 1]);
      if (strcmp("-n", av[i]) == 0 && i + 1 < ac)
  	c->team_name = strdup(av[i + 1]);
      i = i + 2;
    }
  if (c->ip == NULL)
    c->ip = strdup("127.0.0.1");
  if (c->port != 0 && c->team_name != NULL)
    client(c);
  else
    error(84, "missing ");
}

int		main(int ac, char **av)
{
  int		i;

  if (ac > 7 || ac < 2)
    return (84);
  i = 1;
  while (i < ac)
    {
      if (strcmp("-help", av[i]) == 0)
	{
	  help();
	  return (0);
	}
      i++;
    }
  if (ac % 2 == 1)
    pars(ac, av);
  return (0);
}
