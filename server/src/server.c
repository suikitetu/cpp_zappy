/*
** server.c for  in /home/harnis_g/rendu/tek2/PSU/PSU_2016_myirc/src/
**
** Made by Gauthier Harnisch
** Login   <harnis_g@epitech.eu>
**
** Started on  Wed May 24 14:39:12 2017 Gauthier Harnisch
** Last update	Sun Jul 02 19:04:06 2017 Gauthier Harnisch
*/

#include "zappy.h"

volatile t_serv *g_serv = NULL;

void	check_arguments(int ac, char **av)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      if (av[i][0] == '-')
	{
	  if (!(strcmp(av[i], "-p")) || !(strcmp(av[i], "-x")) ||
	      !(strcmp(av[i], "-y")) || !(strcmp(av[i], "-c")) ||
	      !(strcmp(av[i], "-f")))
	    i += 2;
	  else if (!(strcmp(av[i], "-n")))
	    {
	      i++;
	      while (i < ac && av[i][0] != '-')
		i++;
	    }
	  else
	    error(84, "Bad option given");
	}
      else
	i = ac;
    }
}

int	main(int ac, char **av)
{
  t_serv	serv;
  struct sigaction	sigac;

  if (ac > 1 && match(av[1], "--help"))
    return (printf(USAGE) * 0);
  check_arguments(ac, av);
  serv_init(&serv, ac, av);
  g_serv = &serv;
  memset(&sigac, 0, sizeof(sigac));
  sigac.sa_handler = (void (*)(int))cleanup;
  sigaction(SIGINT, &sigac, NULL);
  atexit(cleanup);
  if (listen(serv.net.fd, 10) == -1)
    {
      error(0, "listen failed");
      if (close(serv.net.fd) == -1)
        error(84, "close failed");
      exit(84);
    }
  clock_gettime(CLOCK_MONOTONIC, &serv.last);
  while (1)
    wait_select(&serv);
  g_serv = NULL;
  return (0);
}
