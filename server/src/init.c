/*
** init.c for PSU_2016_myftp
**
** Made by	Gauthier Harnisch
** Login	harins_g
**
** Started on	Thu May 11 17:02:57 2017 Gauthier Harnisch
** Last update	Sun Jul 02 22:34:55 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	net_init(t_net *net, int port)
{
  net->port = port;
  net->pe = getprotobyname("TCP");
  net->s_in.sin_family = AF_INET;
  net->s_in.sin_port = htons(port);
  net->s_in.sin_addr.s_addr = INADDR_ANY;
  if (!net->pe)
    error(84, "getprotobyname failed");
  net->fd = socket(AF_INET, SOCK_STREAM, net->pe->p_proto);
  if (net->fd == -1)
    error(84, "socket failed");
  net->t = 1;
  setsockopt(net->fd, SOL_SOCKET, SO_REUSEADDR, &net->t, sizeof(int));
  net->s_in_size = sizeof(net->s_in_client);
  if (bind(net->fd, (const struct sockaddr *)&net->s_in, sizeof(net->s_in)))
    {
      error(0, "bind failed");
      if (close(net->fd) == -1)
        error(84, "close failed");
      exit(84);
    }
  getsockname(net->fd, (struct sockaddr *)&net->s_in, &net->s_in_size);
}

void	team_dflt(t_serv *serv)
{
  add_team(serv, (char *)"Team1");
  add_team(serv, (char *)"Team2");
  add_team(serv, (char *)"Team3");
  add_team(serv, (char *)"Team4");
}

static void	serv_set_variables(t_serv *serv)
{
  if (!(serv->cli = (t_cli **)malloc(sizeof(t_cli *))) ||
      !(serv->egg = (t_egg **)malloc(sizeof(t_egg *))) ||
      !(serv->team = (t_team **)malloc(sizeof(t_team *))))
    error(84, "malloc failed in serv_init");
  serv->cli[0] = NULL;
  serv->team[0] = NULL;
  serv->egg[0] = NULL;
  serv->len = MAXLINE;
  serv->nb_cli = 0;
  serv->nb_team = 0;
  serv->nb_egg = 0;
  serv->turn = 0;
  serv->sizex = 10;
  serv->sizey = 10;
  serv->boool = 0;
  serv->nb_cli_per_team = 10;
}

void	serv_init(t_serv *serv, int nb, char **arg)
{
  int	port;

  (void)nb;
  (void)arg;
  if (!(serv->cli = (t_cli **)malloc(sizeof(t_cli *))) ||
      !(serv->egg = (t_egg **)malloc(sizeof(t_egg *))) ||
      !(serv->team = (t_team **)malloc(sizeof(t_team *))))
    error(84, "malloc failed in serv_init");
  serv_set_variables(serv);
  signal(SIGPIPE, SIG_IGN);
  port = recup_arg(serv, nb, arg);
  if (serv->boool == 0)
    team_dflt(serv);
  net_init(&serv->net, port);
  printf("port: %d\n", port);
  serv->map = map_generate(serv->sizex, serv->sizex);
}
