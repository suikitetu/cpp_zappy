##
## Makefile for  in /home/harnis_g/rendu/tek2/PSU/PSU_2016_zappy
##
## Made by Harnisch Gauthier
## Login   <harnis_g@epitech.net>
##
## Started on  Fri Jun 23 11:44:52 2017 Harnisch Gauthier
## Last update Sun Jul  2 15:05:57 2017 Benoit Tachet
##

CC      = gcc

RM      = rm -rf

NAME    =../zappy_server

SRCS    =\
	src/server.c \
	src/error.c \
	src/init.c \
	src/cleanup.c \
	src/str.c \
	src/cmd.c \
	src/user.c \
	src/tab.c \
	src/io.c \
	src/team.c \
	src/cycle.c \
	src/circular_buffer.c \
	src/circular_buffer1.c \
	src/select.c \
	src/log.c \
	src/cmd/cmd_example.c \
	src/cmd/forward.c \
	src/cmd/right.c \
	src/cmd/left.c  \
	src/cmd/look.c \
	src/cmd/inventory.c \
	src/cmd/broadcast.c \
	src/cmd/connect_nbr.c \
	src/cmd/fork.c \
	src/cmd/eject.c \
	src/cmd/take.c \
	src/cmd/set.c \
	src/cmd/incantation.c \
	src/cmd/print_ressources.c \
	src/generate_map.c \
	src/recup_arg.c \
	src/death.c \
	src/egg.c \
	src/cmd/graph/map_size.c \
	src/cmd/graph/bct.c \
	src/cmd/graph/sgt.c \
	src/cmd/graph/tna.c \
	src/cmd/graph/plv.c \
	src/cmd/graph/ppo.c \
	src/cmd/graph/pin.c \
	src/cmd/level_low.c  \
	src/cmd/level_high.c  \
	src/fork_graph.c\
	src/strupcase.c\

OBJS    := $(SRCS:src/%.c=obj/%.o)

CFLAGS  = -Iinc -Wall -W -Wextra -ggdb3

all: $(NAME)

obj/%.o : src/%.c
	@mkdir -p obj
	@mkdir -p obj/cmd
	@mkdir -p obj/cmd/graph/
	@$(CC) -c $(CFLAGS) -o $@ $< && \
	echo -e "[\e[32mOK\e[0m]" $< || \
	echo -e "[\e[91;5mERR\e[25m\e[0m]" $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) && \
	echo -e "[\e[32mOK\e[0m] linking" $(NAME) || \
	echo -e "[\e[91;5mERR\e[25m\e[0m] linking" $(NAME) $<

clean:
	@$(RM) $(OBJS) && \
	echo -e "[\e[32mOK\e[0m] deleting .o" || \
	echo -e "[\e[91;5mERR\e[25m\e[0m] deleting .o"

fclean: clean
	@$(RM) $(NAME) && \
	echo -e "[\e[32mOK\e[0m] deleting" $(NAME)|| \
	echo -e "[\e[91;5mERR\e[25m\e[0m] deleting" $(NAME)

re: fclean all

.PHONY: clean fclean re all
