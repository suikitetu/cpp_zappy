/*
** client.h for client in /home/mag_d/rendu/PSU_2016_zappy
**
** Made by david mag
** Login   <mag_d@epitech.net>
**
** Started on  Wed Jun 21 17:36:28 2017 david mag
** Last update	Mon Jun 26 14:46:01 2017 Gauthier Harnisch
*/

#ifndef CLIENT_H_
#define CLIENT_H_

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
# include <stdbool.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/mman.h>

# define MAXLINE 255
# define TIMEOUT 10 // * 1/10^6s
# define BUFFSIZE (MAXLINE << 8)
# define SIZE 255

typedef struct	s_buff
{
  int	max_el;
  int	nb_el;
  void	*data;
  int	beg;
  int	end;
}		t_buff;

typedef struct		s_client
{
  int			port;
  char			*ip;
  struct protoent	*pe;
  int			fd;
  struct sockaddr_in	s_in;
  t_buff	*read;
  t_buff	*write;
}			t_client;

void	client(t_client *c);

int	error(int i, const char *str);

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

int	mwrite(t_buff *buff, int fd);
int	mread(t_buff *buff, int fd);
int	wait_select(t_client *client, double wait);

void	set_target(t_client *cli);
void	set_timeout(long usec);
int	msend(char *msg);
char	*mrecv();

void	end_co(t_client *c);

#endif
