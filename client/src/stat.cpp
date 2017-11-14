//
// player.cpp for player in /home/mag_d/rendu/PSU_2016_zappy/client_src
//
// Made by david mag
// Login   <mag_d@epitech.net>
//
// Started on  Mon Jun 19 16:40:57 2017 david mag
// Last update Fri Jun 30 12:42:09 2017 david mag
//

#include "player.hpp"

player::stat::stat()
{
  this->hunger = 126;
  this->food = 10;
  this->elevation = 1;
  this->mineral.resize(6);
  this->mineral[LINEMATE] = 0;
  this->mineral[DERAUMERE] = 0;
  this->mineral[SIBUR] = 0;
  this->mineral[MENDIANE] = 0;
  this->mineral[PHIRAS] = 0;
  this->mineral[THYSTAME] = 0;
}

player::stat::stat(stat const & stat)
{
  this->hunger = stat.getHunger();
  this->food = stat.getFood();
  this->elevation = stat.getElevation();
  this->mineral.resize(6);
  this->mineral[LINEMATE] = stat.getMineral(LINEMATE);
  this->mineral[DERAUMERE] = stat.getMineral(DERAUMERE);
  this->mineral[SIBUR] = stat.getMineral(SIBUR);
  this->mineral[MENDIANE] = stat.getMineral(MENDIANE);
  this->mineral[PHIRAS] = stat.getMineral(PHIRAS);
  this->mineral[THYSTAME] = stat.getMineral(THYSTAME);
}

player::stat::~stat()
{

}

int		player::stat::getMineral(player::mineralList element) const
{
  return (this->mineral[element]);
}

void		player::stat::setMineral(player::mineralList element, int nbr)
{
  this->mineral[element] = nbr;
}

int		player::stat::getHunger() const
{
  return (this->hunger);
}

void		player::stat::setHunger(int hunger)
{
  this->hunger = hunger;
}

int		player::stat::getElevation() const
{
  return (this->elevation);
}

void		player::stat::setElevation(int elevation)
{
  this->elevation = elevation;
}

int		player::stat::getFood() const
{
  return (this->food);
}

void		player::stat::setFood(int food)
{
  this->food = food;
}

player::stat&	player::stat::operator=(stat const & stat)
{
  this->hunger = stat.getHunger();
  this->elevation = stat.getElevation();
  this->mineral.resize(6);
  this->mineral[LINEMATE] = stat.getMineral(LINEMATE);
  this->mineral[DERAUMERE] = stat.getMineral(DERAUMERE);
  this->mineral[SIBUR] = stat.getMineral(SIBUR);
  this->mineral[MENDIANE] = stat.getMineral(MENDIANE);
  this->mineral[PHIRAS] = stat.getMineral(PHIRAS);
  this->mineral[THYSTAME] = stat.getMineral(THYSTAME);
  return (*this);
}
