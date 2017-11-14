##
## Makefile for  in /home/harnis_g/rendu/tek2/PSU/PSU_2016_zappy
##
## Made by Harnisch Gauthier
## Login   <harnis_g@epitech.net>
##
## Started on  Mon Jun 26 11:37:13 2017 Harnisch Gauthier
## Last update Sun Jul  2 11:01:52 2017 DOYON Etienne
##

NAME		= ../zappy_graphic

CC		= g++ -std=c++11

CCPP		= g++ -std=c++11

SRC		=\
		src/client.c \
		src/wait_select.c \
		src/circular_buffer.c \
		src/circular_buffer1.c \
		src/io.c \
		src/error.c \

SWEET		= $(SRC:.c=.c~)

OBJ		= $(SRC:src/%.c=obj/%.o)

SRC_2		=\
		src/graph.cpp \
		src/draw.cpp \
		src/player.cpp \
		src/connect.cpp \

SWEET_2		= $(SRC_2:.cpp=.cpp~)

OBJ_2		= $(SRC_2:src/%.cpp=obj/%.o)

CFLAGS		= -I./inc -W -Wall -Wextra -ggdb3 -w

CPPFLAGS	= -I./inc -W -Wall -Wextra -ggdb3 -w

OPTIFLAGS	=  -O3 -ffast-math

IRRFLAGS	= -Llib -lIrrlicht -L/usr/X11R6/lib64 -lGL -lXxf86vm -lXext -lX11 -lXcursor

INCFLAGS	= -I../../include -I/usr/X11R6/include -Iinc -Ilib/inc

obj/%.o:	src/%.c
		@mkdir -p obj
		@$(CC) -c $(CFLAGS) -o $@ $< && \
		echo -e "[\e[32mOK\e[0m]" $< || \
		echo -e "[\e[91;5mERR\e[25m\e[0m]" $<

obj/%.o:	src/%.cpp
		@mkdir -p obj
		@$(CCPP) -c $(CPPFLAGS) $(OPTIFLAGS) $(IRRFLAGS) -o $@ $< && \
		echo -e "[\e[32mOK\e[0m]" $< || \
		echo -e "[\e[91;5mERR\e[25m\e[0m]" $<

all:		$(OBJ) $(OBJ_2)
		@$(CCPP) $(INCFLAGS) $(OPTIFLAGS) $(CPPFLAGS) $(OBJ) $(OBJ_2) $(IRRFLAGS) -o $(NAME) && \
		 echo -e "[\e[32mOK\e[0m] linking" ||\
		 echo -e "[\e[91;5mERR\e[25m\e[0m]"

clean:
		@rm -rf $(SWEET)
		@rm -rf $(OBJ)
		@rm -rf $(SWEET_2)
		@rm -rf $(OBJ_2)
		@rm -rf Makefile~
		@echo -e "[\e[32mOK\e[0m] cleaning *.o *~"

fclean:		clean
		@rm -rf ../zappy_graphic
		@rm -rf $(NAME)
		@echo -e "[\e[32mOK\e[0m] deleting" $(NAME)

re:		fclean all
