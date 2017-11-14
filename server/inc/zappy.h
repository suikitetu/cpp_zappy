/*
** zappy.h for PSU_2016_zappy
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Mon Jun 19 14:28:55 2017 Gauthier Harnisch
** Last update	Sun Jul 02 20:26:17 2017 Gauthier Harnisch
*/

#ifndef _ZAPPY_H_
# define _ZAPPY_H_

# include <sys/socket.h>
# include <netdb.h>
# include <errno.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <linux/unistd.h>
# include <unistd.h>
# include <string.h>
# include <time.h>
# include <limits.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include "map.h"

# define MAXLINE 255
# define BUFFSIZE (1 << 16)
# define SIZE 255

# define GRAPHIC (1 << 0)
# define AI (1 << 1)
# define DEAD (1 << 2)

# define ABS(x) ((x > 0) ? (x) : (-x))

# define CYCLE_US 1000000

# define SEP " ,\t"
# define ALLOW "azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN\
 0123456789/_."
#define USAGE "USAGE: ./zappy_server.html -p port -x width -y height -n\
 name1 name2 ... -c clientsNb -f freq\n\
\n\tport      is the port number\n\
\twidth     is the width of the world\n\
\theight    is the height of the world\n\
\tnameX     is the name of the team X\n\
\tclientsNb is the number of authorized clients per team\n\
\tfreq      is the reciprocal of time unit for execution of actions\b\
\n"

# define UP 1
# define RIGHT 2
# define DOWN 3
# define LEFT 4

struct s_serv;
struct s_team;

typedef void	(*fct)(struct s_serv *serv, int i, char **tab);
typedef void	(*handle)(struct s_serv *serv, int i);
typedef void	(*incant)(struct s_serv *serv, int i);

typedef struct	s_net
{
  struct protoent	*pe;
  int	fd;
  struct sockaddr_in	s_in;
  int	port;
  int	t;
  struct sockaddr_in	s_in_client;
  socklen_t	s_in_size;
  int	client_fd;
  char	*client_ip;
  int	server;
}t_net;

typedef struct	s_buff
{
  int	max_el;
  int	nb_el;
  void	*data;
  int	beg;
  int	end;
}t_buff;

typedef struct	s_cli
{
  int	id;
  struct s_team	*team;
  t_buff	*read;
  t_buff	*write;
  t_map		*pos;
  int	fd;
  int	dir;
  handle	expect;
  fct	func;
  int	cycle_to_exec;
  char	*msg;
  int	level;
  int	inventory[7];
  int	flag;
  int	incanting_end;
  int	life;
}t_cli;

typedef struct	s_team
{
  char	*name;
  int	nb_user;
  t_cli	**user;
  int	max_nb_players;
  long	*cycles_to_add_clients;
  int	size_cyclearray;
}t_team;

typedef struct	s_egg
{
  int	id;
  t_team	*team;
  t_map	*pos;
  int	food;
  int	life;
  int	hatched;
  long	turn_to_hatch;
}t_egg;

typedef struct	s_serv
{
  struct timespec last;
  t_net	net;
  struct timespec beg;
  int	nb_cli_per_team;
  int	nb_cli;
  int	nb_team;
  int	sizex;
  int	sizey;
  char	*buf;
  int	len;
  t_cli	**cli;
  t_team	**team;
  long	us;
  long	turn;
  t_map	**map;
  int	cycle;
  int	boool;
  int	flag;
  int	nb_egg;
  t_egg	**egg;
}t_serv;

typedef struct s_cmd
{
  const char *name;
  fct	func;
  int	time;
  int	flag;
}t_cmd;

void	net_init(t_net *net, int port);
void	serv_init(t_serv *serv, int nb, char **arg);

void	cleanup();

int	error(int i, const char *str);

char	**str_tab(char *str);

int	match(const char *s1, const char *s2);
char	*extract(const char *line, int d, int f);
char	*clean_str(const char *i, const char *allow);
char	*combine(const char *str, const char *add);

void	add_client(t_serv *serv);
int	remove_client(t_serv *serv, int k);

int	mread(t_buff *buff, int fd);

void	wait_select(t_serv *serv);

void	add_team(t_serv *serv, char *name);
void	talk_team(t_serv *serv, t_team *team, int cli);
void	add_to_team(t_team *team, t_cli *cli);
int	remove_team(t_serv *serv, int k);
void	leave_team(t_team *team, t_cli *cli);

int	pop_cmd(t_serv *serv, int i);
int	exec_cmd(t_serv *serv, int k);
int	cmd(t_serv *serv, int i);
void	graph_msg_fork(t_serv *serv, int k);
char	*strdup(const char *s);
int	dprintf(int fildes, const char *format, ...);

int	send_cli(t_cli *cli, char *msg);
void	send_graph(t_serv *serv, char *msg);

void	cycle(t_serv *serv);

t_buff	*new_buff(int nb_el);
char	*buff_pop_line(t_buff *buff);
t_buff	*buff_move_end(t_buff *buff, int i);
t_buff	*buff_push_front(t_buff *buff, char *data, int size);
char	*buff_pop_front(t_buff *buff, int size);
char	*buff_get(t_buff *buff);
t_buff	*buff_push_back(t_buff *buff, char *data, int size);
char	*buff_pop_back(t_buff *buff, int size);
t_buff	*buff_empty(t_buff *buff);
void	del_buff(t_buff *buff);

char	*buff_pop_char(t_buff *buff, char c);

int	mwrite(t_buff *buff, int fd);
int	mread(t_buff *buff, int fd);

void	death(t_serv *serv, int i);
void	death_egg(t_serv *serv, int i);

void	new_egg(t_serv *serv, int k);
void	remove_egg(t_serv *serv, int k);
void	find_egg(t_serv *serv, int i);
void	 check_egg(t_serv *serv);

void	cmd_example(t_serv *serv, int i, char **tab);
void	forward(t_serv *serv, int i, char **tab);
void	right(t_serv *serv, int i, char **tab);
void	left(t_serv *serv, int i, char **tab);
void	look(t_serv *serv, int i, char **tab);
void	inventory(t_serv *serv, int i, char **tab);
void	broadcast(t_serv *serv, int i, char **tab);
void	connect_nbr(t_serv *serv, int i, char **tab);
void	mfork(t_serv *serv, int i, char **tab);
void	eject(t_serv *serv, int i, char **tab);
void	take(t_serv *serv, int i, char **tab);
void	set(t_serv *serv, int i, char **tab);
void	incantation(t_serv *serv, int i, char **tab);

void	msz(t_serv *serv, int i, char **tab);
void	bctxy(t_serv *serv, int i, char **tab);
void	bct(t_serv *serv, int i, char **tab);
void	sgt(t_serv *serv, int i, char **tab);
void	sst(t_serv *serv, int i, char **tab);
void	tna(t_serv *serv, int i, char **tab);
void    pdi(t_serv *serv, int i);

void	print_ressources(t_serv *serv, t_map *pos, t_cli *cli);
int	recup_arg(t_serv *serv, int ac, char **av);
void    unkown_cmd(t_serv *serv, int i, char **tab);
int     is_num(char *str);
int     cmp_team(char *str, t_serv *serv);

char		*itoa(int i);
void		level1(t_serv *serv, int i);
void		level2(t_serv *serv, int i);
void		level3(t_serv *serv, int i);
void		level4(t_serv *serv, int i);
void		level5(t_serv *serv, int i);
void		level6(t_serv *serv, int i);
void		level7(t_serv *serv, int i);
void		level8(t_serv *serv, int i);
void		incantation_message(t_cli *cli);
int		check_nummap(t_serv *serv, int i);
void		levelup(t_serv *serv, int i);
void		logg(t_serv *serv, int i);

char	*strupcase(char *str);

#endif
