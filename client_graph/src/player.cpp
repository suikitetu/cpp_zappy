//
// player.cpp for  in /home/doyon_e/rendu/semestre_4/PSU/PSU_2016_zappy/client_graph
// 
// Made by DOYON Etienne
// Login   <doyon_e@epitech.net>
// 
// Started on  Tue Jun 27 14:52:31 2017 DOYON Etienne
// Last update Sun Jul  2 20:37:30 2017 DOYON Etienne
//

#include "graph.hpp"

Egg::Egg()
{
  this->is_rdy = 0;
}

Egg::Egg(char *&str, Player_list *pl)
{
  std::stringstream	my_value(str);
  std::string		tmp;

  my_value >> tmp;
  my_value >> tmp;
  this->ID = std::stoi(tmp);
  my_value >> tmp;
  this->team = pl->getteam(std::stoi(tmp));
  my_value >> tmp;
  this->X = std::stoi(tmp);
  my_value >> tmp;
  this->Y = std::stoi(tmp);
  this->is_rdy = 1;
}

Player::Player()
{
  this->selected = 0;
  this->POSX = rand() % 20;
  this->POSY = rand() % 20;
}

Player::Player(char *&str)
{
  std::stringstream	my_value(str);
  std::string		tmp;

  this->selected = 0;
  this->POSX = rand() % 20;
  this->POSY = rand() % 20;
  my_value >> tmp;
  my_value >> tmp;
  this->ID = std::stoi(tmp);
  my_value >> tmp;
  this->X = std::stoi(tmp);
  my_value >> tmp;
  this->Y = std::stoi(tmp);
  my_value >> tmp;
  this->orient = std::stoi(tmp);
  my_value >> tmp;
  this->level = std::stoi(tmp);
  my_value >> tmp;
  this->team = tmp;
}

Player_list::Player_list()
{
}

void	Player_list::move_player(char *&str, Map *map)
{
  std::stringstream	my_value(str);
  std::string		tmp;
  int			i;
  int			IMOVE;

  my_value >> tmp;
  my_value >> tmp;
  i = -1;
  IMOVE = 0;
  while ((unsigned int)++i != this->list.size())
    {
      if (this->list[i].ID == std::stoi(tmp))
	{
	  my_value >> tmp;
	  if (this->list[i].X != std::stoi(tmp))
	    IMOVE = 1;
	  this->list[i].X = std::stoi(tmp);
	  my_value >> tmp;
          if (this->list[i].Y != std::stoi(tmp))
	    IMOVE = 1;
	  this->list[i].Y = std::stoi(tmp);
          my_value >> tmp;
	  this->list[i].orient = std::stoi(tmp);
	  if (this->list[i].selected == 1 && IMOVE == 1)
	    {
	      if (this->list[i].orient == 1)
		map->MappingY = map->MappingY - 1;
	      else if (this->list[i].orient == 2)
		map->MappingX = map->MappingX + 1;
	      else if (this->list[i].orient == 3)
		map->MappingY = map->MappingY + 1;
	      else
		map->MappingX = map->MappingX - 1;
	    }
	}
    }
}

void	Player_list::kys(char *&str)
{
  std::stringstream     my_value(str);
  std::string           tmp;
  int                   i;

  my_value >> tmp;
  my_value >> tmp;
  i = -1;
  while ((unsigned int)++i != this->list.size())
    {
      if (this->list[i].ID == std::stoi(tmp))
	{
	  this->list[i].X = -1;
	  this->list[i].Y = -1;
	}
    }
}

void	Player_list::die_fcking_egg(char *&str)
{
  std::stringstream     my_value(str);
  std::string           tmp;
  int                   i;

  my_value >> tmp;
  my_value >> tmp;
  i = -1;
  while ((unsigned int)++i != this->list2.size())
    {
      if (this->list2[i].ID == std::stoi(tmp))
	{
	  this->list2[i].X = -1;
	  this->list2[i].Y = -1;
	}
    }
}

void	Player_list::levelup(char *&str)
{
  std::stringstream     my_value(str);
  std::string           tmp;
  int                   i;

  my_value >> tmp;
  my_value >> tmp;
  i = -1;
  while ((unsigned int)++i != this->list.size())
    {
      if (this->list[i].ID == std::stoi(tmp))
	{
	  my_value >> tmp;
	  this->list[i].level = std::stoi(tmp);
	}
    }
}

void	Player_list::add_list(char *&str)
{
  Player	pl(str);

  this->list.push_back(pl);
}

void	Player_list::add_list2(char *&str)
{
  Egg		e(str, this);

  this->list2.push_back(e);
}

std::string	Player_list::getteam(int ID)
{
  int	i;

  i = -1;
  while ((unsigned int)++i != this->list.size())
    if (this->list[i].ID == ID)
      return (this->list[i].team);
  return ("");
}

void    Player_list::rdy(char *&str)
{
  std::stringstream     my_value(str);
  std::string           tmp;
  int                   i;

  my_value >> tmp;
  my_value >> tmp;
  i = -1;
  while ((unsigned int)++i != this->list2.size())
    {
      if (this->list2[i].ID == std::stoi(tmp))
	{
	  my_value >> tmp;
	  this->list2[i].is_rdy = std::stoi(tmp);
	}
    }
}
