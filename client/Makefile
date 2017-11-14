##
## Makefile for  in /home/harnis_g/rendu/tek2/PSU/PSU_2016_zappy
##
## Made by Harnisch Gauthier
## Login   <harnis_g@epitech.net>
##
## Started on  Mon Jun 26 15:58:21 2017 Harnisch Gauthier
## Last update Sun Jul  2 14:09:03 2017 david mag
##

NAME		= ../zappy_ai

CC		= g++

CCPP		= g++

SRC		=\
		src/main.c \
		src/client.c \
		src/wait_select.c \
		src/circular_buffer.c \
		src/circular_buffer1.c \
		src/io.c \
		src/error.c \
		src/str.c \
		src/my_str_to_wordtab.c \

SWEET		= $(SRC:.c=.c~)

OBJ		= $(SRC:src/%.c=obj/%.o)

SRC_2		=\
		src/wordtab.cpp \
		src/script.cpp \
		src/command.cpp \
		src/stat.cpp \
		src/ai.cpp \

SWEET_2		= $(SRC_2:.cpp=.cpp~)

OBJ_2		= $(SRC_2:src/%.cpp=obj/%.o)

CFLAGS		= -I./inc -W -Wall -Wextra -ggdb3 -std=c++11

CPPFLAGS	= -I./inc -W -Wall -Wextra -ggdb3 -std=c++11

obj/%.o:	src/%.c
		@mkdir -p obj
		@$(CCPP) -c $(CFLAGS) -o $@ $< && \
		echo -e "[\e[32mOK\e[0m]" $< || \
		echo -e "[\e[91;5mERR\e[25m\e[0m]" $<

obj/%.o:	src/%.cpp
		@mkdir -p obj
		@$(CCPP) -c $(CPPFLAGS) -o $@ $< && \
		echo -e "[\e[32mOK\e[0m]" $< || \
		echo -e "[\e[91;5mERR\e[25m\e[0m]" $<

all:		$(OBJ) $(OBJ_2)
		@g++ $(CPPFLAGS) $(OBJ) $(OBJ_2) -o $(NAME) && \
		echo -e "[\e[32mOK\e[0m] linking" || \
		echo -e "[\e[91;5mERR\e[25m\e[0m]"

clean:
		@rm -rf $(SWEET)
		@rm -rf $(OBJ)
		@rm -rf $(SWEET_2)
		@rm -rf $(OBJ_2)
		@rm -rf Makefile~
		@echo -e "[\e[32mOK\e[0m] cleaning *.o *~"

fclean:		clean
		@rm -rf $(NAME)
		@echo -e "[\e[32mOK\e[0m] deleting" $(NAME)

re:		fclean all
