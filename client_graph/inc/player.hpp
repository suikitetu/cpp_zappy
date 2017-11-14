//
// player.hpp for  in /home/doyon_e/rendu/semestre_4/PSU/PSU_2016_zappy/client_graph
// 
// Made by DOYON Etienne
// Login   <doyon_e@epitech.net>
// 
// Started on  Tue Jun 27 13:44:45 2017 DOYON Etienne
// Last update Sun Jul  2 20:15:56 2017 DOYON Etienne
//

#ifndef _MY_PLAYER_HPP_

#include "graph.hpp"
#include <vector>
#include <string>

class Player_list;
class Map;

class	Egg
{
public:
  std::string	team;
  int		X;
  int		Y;
  int		ID;
  int		is_rdy;

  Egg();
  Egg(char *&str, Player_list *pl);
};

class	Player
{
public:
  std::string   team;
  int           orient;
  int           X;
  int           Y;
  int           level;
  int           ID;
  int		POSX;
  int		POSY;
  int		selected;

  Player();
  Player(char *&str);
};

class	Player_list
{
public:
  std::vector<Player>	list;
  std::vector<Egg>	list2;

  Player_list();

  void	kys(char *&str);
  void	levelup(char *&str);
  void	add_list(char *&str);
  void	add_list2(char *&str);
  void	move_player(char *&str, Map *mmap);

  void	rdy(char *&str);
  void	die_fcking_egg(char *&str);

  std::string	getteam(int ID);
};

#endif
