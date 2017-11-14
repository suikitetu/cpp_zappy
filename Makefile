##
## Makefile for  in /home/harnis_g/rendu/tek2/PSU/PSU_2016_zappy
##
## Made by Harnisch Gauthier
## Login   <harnis_g@epitech.net>
##
## Started on  Fri Jun 23 14:00:56 2017 Harnisch Gauthier
## Last update Thu Jun 29 16:21:01 2017 Sébastien Blineau
##

NAME	=zappy_server

NAME1	=zappy_ai

NAME2	=zappy_graphic

all:	$(NAME) $(NAME1) $(NAME2)

$(NAME):
	@$(MAKE) -C server all

$(NAME1):
	@$(MAKE) -C client all

$(NAME2): install
	@$(MAKE) -C client_graph all

clean:
	@$(MAKE) -C server clean
	@$(MAKE) -C client clean
	@$(MAKE) -C client_graph clean

fclean: uninstall
	@$(MAKE) -C server fclean
	@$(MAKE) -C client fclean
	@$(MAKE) -C client_graph fclean

re: install
	@$(MAKE) -C server re
	@$(MAKE) -C client re
	@$(MAKE) -C client_graph re

install:
	@echo -e "installing..."
	@mkdir -p client_graph/lib
	@tar -xzf irrlich/irr.tar.gz -C client_graph/lib && \
	echo -e "[\e[32mOK\e[0m] irrlich installed" || \
        echo -e "[\e[32mOK\e[0m] irrlich already installed"

uninstall:
	@echo -e "uninstalling..."
	@rm -rf client_graph/lib && \
        echo -e "[\e[32mOK\e[0m] irrlich uninstalled" || \
        echo -e "[\e[32mOK\e[0m] irrlich already uninstalled"

.PHONY: clean fclean re all install uninstall
