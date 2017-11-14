//
// command.cpp for command in /home/mag_d/rendu/PSU_2016_zappy/client_src
//
// Made by david mag
// Login   <mag_d@epitech.net>
//
// Started on  Tue Jun 20 11:49:02 2017 david mag
// Last update Sun Jul  2 19:56:32 2017 david mag
//

#include "player.hpp"

player::command::command(int mapSizeX, int mapSizeY) : stat()
{
  int	myX;
  int	myY;

  myX = 0;
  this->mapVision.resize(mapSizeX);
  while (myX < mapSizeX)
    {
      this->mapVision[myX].resize(mapSizeY);
      myY = 0;
      while (myY < mapSizeY)
	{
	  this->mapVision[myX][myY].food = 0;
	  this->mapVision[myX][myY].mineral.resize(6);
	  this->mapVision[myX][myY].mineral[LINEMATE] = 0;
	  this->mapVision[myX][myY].mineral[DERAUMERE] = 0;
	  this->mapVision[myX][myY].mineral[SIBUR] = 0;
	  this->mapVision[myX][myY].mineral[MENDIANE] = 0;
	  this->mapVision[myX][myY].mineral[PHIRAS] = 0;
	  this->mapVision[myX][myY].mineral[THYSTAME] = 0;
	  this->mapVision[myX][myY].player = 0;
	  this->mapVision[myX][myY].lastSeen = 0;
	  myY++;
	}
      myX++;
    }
  this->oriantation = OUEST;
  this->elevation = 1;
  this->mapSizeX = mapSizeX;
  this->mapSizeY = mapSizeY;
  this->posX = mapSizeX / 2;
  this->posY = mapSizeY / 2;
  this->f = 0;
}

player::command::command(command const & command) : stat(command)
{
  int	myX;
  int	myY;

  myX = 0;
  this->mapVision.resize(mapSizeX);
  while (myX < mapSizeX)
    {
      this->mapVision[myX].resize(mapSizeY);
      myY = 0;
      while (myY < mapSizeY)
	{
	  this->mapVision[myX][myY].food = 0;
	  this->mapVision[myX][myY].mineral.resize(6);
	  this->mapVision[myX][myY].mineral[LINEMATE] = 0;
	  this->mapVision[myX][myY].mineral[DERAUMERE] = 0;
	  this->mapVision[myX][myY].mineral[SIBUR] = 0;
	  this->mapVision[myX][myY].mineral[MENDIANE] = 0;
	  this->mapVision[myX][myY].mineral[PHIRAS] = 0;
	  this->mapVision[myX][myY].mineral[THYSTAME] = 0;
	  this->mapVision[myX][myY].player = 0;
	  this->mapVision[myX][myY].lastSeen = 0;
	  myY++;
	}
      myX++;
    }
  this->oriantation = OUEST;
  this->elevation = 1;
  this->mapSizeX = mapSizeX;
  this->mapSizeY = mapSizeY;
  this->posX = mapSizeX / 2;
  this->posY = mapSizeY / 2;
  this->f = 0;
}

player::command::~command()
{

}

int					player::command::getOriantation()
{
  return (this->oriantation);
}

void					player::command::setMapSizeX(int mapSizeX)
{
  this->mapSizeX = mapSizeX;
}

int					player::command::getMapSizeX() const
{
  return (this->mapSizeX);
}

void					player::command::setMapSizeY(int mapSizeY)
{
  this->mapSizeY = mapSizeY;
}

int					player::command::getMapSizeY() const
{
  return (this->mapSizeY);
}

void					player::command::setPosX(int posX)
{
  this->posX = posX;
}

int					player::command::getPosX() const
{
  return (this->posX);
}

void					player::command::setPosY(int posY)
{
  this->posY = posY;
}

int					player::command::getPosY() const
{
  return (this->posY);
}

int					*player::command::findFood() const
{
  int					x;
  int					y;
  int					*res;
  int					distance;
  int					distance_tmp;

  distance = -1;
  x = 0;
  res = new int[2];
  while (x < this->mapSizeX)
    {
      y = 0;
      while (y < this->mapSizeY)
	{
	  // this->f - this->mapVision[x][y].lastSeen < LAST_FOOD
	  if (this->mapVision[x][y].food > 0)
	    {
	      distance_tmp = ((x - this->posX)*(x - this->posX)) + ((y - this->posY)*(y - this->posY));
	      if (distance == -1 || distance > distance_tmp)
		{
		  distance = distance_tmp;
		  res[0] = x;
		  res[1] = y;
		}
	    }
	  y++;
	}
      x++;
    }
  if (distance == -1)
    return (NULL);
  return (res);
}

int					*player::command::findMineral(mineralList element) const
{
  int					x;
  int					y;
  int					*res;
  int					distance;
  int					distance_tmp;

  distance = -1;
  x = 0;
  res = new int[2];
  while (x < this->mapSizeX)
    {
      y = 0;
      while (y < this->mapSizeY)
	{
	  if (this->mapVision[x][y].mineral[element] > 0
	      && this->f - this->mapVision[x][y].lastSeen < LAST_MINERAL)
	    {
	      distance_tmp = ((x - this->posX)*(x - this->posX)) + ((y - this->posY)*(y - this->posY));
	      if (distance == -1 || distance > distance_tmp)
		{
		  distance = distance_tmp;
		  res[0] = x;
		  res[1] = y;
		}
	    }
	  y++;
	}
      x++;
    }
  if (distance == -1)
    return (NULL);
  return (res);
}

player::t_tile const			player::command::getTile(int x, int y) const
{
  return (this->mapVision[x][y]);
}

void					player::command::forward()
{
  if (this->oriantation == NORD)
    this->posY = (posY + 1) % this->mapSizeY;
  else if (this->oriantation == EST)
    this->posX = (posX + 1) % this->mapSizeX;
  else if (this->oriantation == SUD)
    this->posY = (posY - 1) % this->mapSizeY;
  else if (this->oriantation == OUEST)
    this->posX = (posX - 1) % this->mapSizeX;
  msend((char *)"Forward\n");
  playerReceive();
  this->f = this->f + 7;
}

void					player::command::setOriantation(player::oriantation end)
{
  if ((this->oriantation + 1) % 4 == end)
    turnRight();
  else if ((this->oriantation + 3) % 4 == end)
    turnLeft();
  else if ((this->oriantation + 2) % 4 == end)
    {
      turnRight();
      turnRight();
    }
}

void					player::command::turnRight()
{
  this->oriantation = (oriantation + 1) % 4;
  msend((char *)"Right\n");
  playerReceive();
  this->f = this->f + 7;
}

void					player::command::turnLeft()
{
  this->oriantation = (oriantation + 3) % 4;
  msend((char *)"Left\n");
  playerReceive();
  this->f = this->f + 7;
}

void					player::command::setTile(std::string str, int x, int y)
{
  int	i;
  std::vector<std::string>		stuff;

  while (x < 0)
    x = x + this->mapSizeX;
  while (y < 0)
    y = y + this->mapSizeY;
  stuff = wordtab((char *)str.c_str(), ' ');
  this->mapVision[x][y].food = 0;
  this->mapVision[x][y].mineral[LINEMATE] = 0;
  this->mapVision[x][y].mineral[DERAUMERE] = 0;
  this->mapVision[x][y].mineral[SIBUR] = 0;
  this->mapVision[x][y].mineral[MENDIANE] = 0;
  this->mapVision[x][y].mineral[PHIRAS] = 0;
  this->mapVision[x][y].mineral[THYSTAME] = 0;
  this->mapVision[x][y].player = 0;
  this->mapVision[x][y].lastSeen = this->f;
  i = 0;
  while (i < (int)stuff.size())
    {
      if (stuff[i] == "food")
	this->mapVision[x][y].food = this->mapVision[x][y].food + 1;
      if (stuff[i] == "player")
	this->mapVision[x][y].player = this->mapVision[x][y].player + 1;
      if (stuff[i] == "linemate")
	this->mapVision[x][y].mineral[LINEMATE] = this->mapVision[x][y].mineral[LINEMATE] + 1;
      if (stuff[i] == "deraumere")
	this->mapVision[x][y].mineral[DERAUMERE] = this->mapVision[x][y].mineral[DERAUMERE] + 1;
      if (stuff[i] == "sibur")
	this->mapVision[x][y].mineral[SIBUR] = this->mapVision[x][y].mineral[SIBUR] + 1;
      if (stuff[i] == "mendiane")
	this->mapVision[x][y].mineral[MENDIANE] = this->mapVision[x][y].mineral[MENDIANE] + 1;
      if (stuff[i] == "phiras")
	this->mapVision[x][y].mineral[PHIRAS] = this->mapVision[x][y].mineral[PHIRAS] + 1;
      if (stuff[i] == "thystame")
	this->mapVision[x][y].mineral[THYSTAME] = this->mapVision[x][y].mineral[THYSTAME] + 1;
      i++;
    }
  stuff.clear();
}

void					player::command::lookNord(std::vector<std::string> tab)
{
  int					i;
  int					c;
  int					n;

  n = 0;
  i = 0;
  while (i <= this->elevation)
    {
      c = -i;
      while (c <= i)
	{
	  if (n >= (int)tab.size())
	    return ;
	  setTile(tab[n], (this->posX + c) % this->mapSizeX, (this->posY + i) % this->mapSizeY);
	  c++;
	  n++;
	}
      i++;
    }
}

	  // if (n > (int)tab.size())
	  //   return ;

void					player::command::lookEst(std::vector<std::string> tab)
{
  int					i;
  int					c;
  int					n;

  n = 0;
  i = 0;
  while (i <= this->elevation)
    {
      c = -i;
      while (c <= i)
	{
	  if (n >= (int)tab.size())
	    return ;
	  setTile(tab[n], (this->posX + i) % this->mapSizeX,
		  (this->posY + this->mapSizeY - c) % this->mapSizeY);
	  c++;
	  n++;
	}
      i++;
    }
}

	  // if (n > (int)tab.size())
	  //   return ;

void					player::command::lookSud(std::vector<std::string> tab)
{
  int					i;
  int					c;
  int					n;

  n = 0;
  i = 0; 
  while (i <= this->elevation)
    {
      c = -i;
      while (c <= i)
	{
	  if (n >= (int)tab.size())
	    return ;
	  setTile(tab[n], (this->posX + this->mapSizeY - c) % this->mapSizeX,
		  (this->posY + this->mapSizeY - i) % this->mapSizeY);
	  c++;
	  n++;
	}
      i++;
    }
}


void					player::command::lookOuest(std::vector<std::string> tab)
{
  int					i;
  int					c;
  int					n;

  n = 0;
  i = 0;
  while (i <= this->elevation)
    {
      c = -i;
      while (c <= i)
	{
	  if (n >= (int)tab.size())
	    return ;
	  setTile(tab[n], (this->posX + this->mapSizeY - i) % this->mapSizeX,
		  (this->posY + c) % this->mapSizeY);
	  c++;
	  n++;
	}
      i++;
    }
}


void					player::command::look()
{
  char					*str;
  std::vector<std::string>		tab;
  std::cmatch				cm;
  int					i;
  std::regex				r_num_1("\\[ ?([A-Za-z ]*,?){4}\\]");
  std::regex				r_num_2("\\[ ?([A-Za-z ]*,?){9}\\]");
  std::regex				r_num_3("\\[ ?([A-Za-z ]*,?){16}\\]");
  std::regex				r_num_4("\\[ ?([A-Za-z ]*,?){25}\\]");
  std::regex				r_num_5("\\[ ?([A-Za-z ]*,?){36}\\]");
  std::regex				r_num_6("\\[ ?([A-Za-z ]*,?){49}\\]");
  std::regex				r_num_7("\\[ ?([A-Za-z ]*,?){64}\\]");
  std::regex				r_num_8("\\[ ?([A-Za-z ]*,?){81}\\]");
  bool					test;
  
  msend((char *)"Look\n");
  this->f = this->f + 7;
  str = playerReceive();
  test = false;
  if (std::regex_match(str, cm, r_num_1))
    test = true;
  if (std::regex_match(str, cm, r_num_2))
    test = true;
  if (std::regex_match(str, cm, r_num_3))
    test = true;
  if (std::regex_match(str, cm, r_num_4))
    test = true;
  if (std::regex_match(str, cm, r_num_5))
    test = true;
  if (std::regex_match(str, cm, r_num_6))
    test = true;
  if (std::regex_match(str, cm, r_num_7))
    test = true;
  if (std::regex_match(str, cm, r_num_8))
    test = true;
  if (test == false)
    return ;
  i = 1;
  while (str[i])
    {
      str[i - 1] = str[i];
      i++;
    }
  str[i - 2] = '\0';
  str[i - 1] = '\0';
  tab = wordtab(str, ',');
  if (this->oriantation == NORD)
    lookNord(tab);
  else if (this->oriantation == EST)
    lookEst(tab);
  else if (this->oriantation == SUD)
    lookSud(tab);
  else if (this->oriantation == OUEST)
    lookOuest(tab);
  tab.clear();
}

void					player::command::inventory()
{
  char					*str;
  std::regex				r_num("\\[ ?([A-Za-z]+) ([0-9]+),? ?([A-Za-z]+) ([0-9]+),? ?([A-Za-z]+) ([0-9]+),? ?([A-Za-z]+) ([0-9]+),? ?([A-Za-z]+) ([0-9]+),? ?([A-Za-z]+) ([0-9]+),? ?([A-Za-z]+) ([0-9]+),? ?\\]");
  std::cmatch				cm;
  int					i;

  msend((char *)"Inventory\n");
  this->f = this->f + 1;
  str = playerReceive();
  i = 1;
  if (std::regex_match(str, cm, r_num))
    {
      if (cm[i] == "food")
	this->food = std::atoi(cm[i + 1].str().c_str());
      if (cm[i] == "linemate")
	this->mineral[LINEMATE] = std::atoi(cm[i + 1].str().c_str());
      if (cm[i] == "deraumere")
	this->mineral[DERAUMERE] = std::atoi(cm[i + 1].str().c_str());
      if (cm[i] == "sibur")
	this->mineral[SIBUR] = std::atoi(cm[i + 1].str().c_str());
      if (cm[i] == "mendiane")
	this->mineral[MENDIANE] = std::atoi(cm[i + 1].str().c_str());
      if (cm[i] == "phiras")
	this->mineral[PHIRAS] = std::atoi(cm[i + 1].str().c_str());
      if (cm[i] == "thystame")
	this->mineral[THYSTAME] = std::atoi(cm[i + 1].str().c_str());
      i = i + 2;
    }
}

void					player::command::broadcastText(std::string message)
{
  msend((char *)"Broadcast ");
  msend((char *)message.c_str());
  msend((char *)"\n");
  this->f = this->f + 7;
  playerReceive();
}

void					player::command::connectNbr()
{
  msend((char *)"Conect_nbr\n");
  playerReceive();
}

void					player::command::forkPlayer()
{

  msend((char *)"Fork\n");
  this->f = this->f + 42;
  playerReceive();
}

bool					player::command::ejectPlayer()
{
  msend((char *)"Eject\n");
  this->f = this->f + 7;
  if (strcmp(playerReceive(), "ok") == 0)
    return (true);
  return (false);
}

void					player::command::death()
{

}

void					player::command::clean()
{
  while (mapVision[this->posX][this->posY].food > 0)
    takeObject("food", LINEMATE, true);
  while (mapVision[this->posX][this->posY].mineral[LINEMATE] > 0)
    takeObject("linemate", LINEMATE, false);
  while (mapVision[this->posX][this->posY].mineral[DERAUMERE] > 0)
    takeObject("deraumere", DERAUMERE, false);
  while (mapVision[this->posX][this->posY].mineral[SIBUR] > 0)
    takeObject("sibur", SIBUR, false);
  while (mapVision[this->posX][this->posY].mineral[MENDIANE] > 0)
    takeObject("mendiane", MENDIANE, false);
  while (mapVision[this->posX][this->posY].mineral[PHIRAS] > 0)
    takeObject("phiras", PHIRAS, false);
  while (mapVision[this->posX][this->posY].mineral[THYSTAME] > 0)
    takeObject("thystame", THYSTAME, false);
}

void					player::command::takeObject(std::string object, mineralList element, bool food)
{
  std::string				str;

  msend((char *)"Take ");
  msend((char *)object.c_str());
  msend((char *)"\n");
  str = playerReceive();
  this->f = this->f + 7;
  if (str == "ok")
    {
      if (food == true)
	{
	  this->mapVision[this->posX][this->posY].food =
	    this->mapVision[this->posX][this->posY].food - 1;
	  this->food = food + 1;
	}
      else
	{
	  this->mapVision[this->posX][this->posY].mineral[element] =
	    this->mapVision[this->posX][this->posY].mineral[element] - 1;
	  this->mineral[element] = this->mineral[element] + 1;
	}
    }
  else
    {
      if (food == true)
	this->mapVision[this->posX][this->posY].food = 0;
      else
	this->mapVision[this->posX][this->posY].mineral[element] = 0;
    }
}

void					player::command::place()
{
  while (mapVision[this->posX][this->posY].mineral[LINEMATE] < prerequiIncantation[this->elevation][0])
    setObject("linemate", LINEMATE, false);
  while (mapVision[this->posX][this->posY].mineral[DERAUMERE] < prerequiIncantation[this->elevation][1])
    setObject("deraumere", DERAUMERE, false);
  while (mapVision[this->posX][this->posY].mineral[SIBUR] < prerequiIncantation[this->elevation][2])
    setObject("sibur", SIBUR, false);
  while (mapVision[this->posX][this->posY].mineral[MENDIANE] < prerequiIncantation[this->elevation][3])
    setObject("mendiane", MENDIANE, false);
  while (mapVision[this->posX][this->posY].mineral[PHIRAS] < prerequiIncantation[this->elevation][4])
    setObject("phiras", PHIRAS, false);
  while (mapVision[this->posX][this->posY].mineral[THYSTAME] < prerequiIncantation[this->elevation][5])
    setObject("thystame", THYSTAME, false);
}

void					player::command::setObject(std::string object, mineralList element, bool food)
{
  std::string				str;

  msend((char *)"Set ");
  msend((char *)object.c_str());
  msend((char *)"\n");
  str = playerReceive();
  this->f = this->f + 7;
  if (str == "ok")
    {
      if (food == true)
	{
	  this->mapVision[this->posX][this->posY].food =
	    this->mapVision[this->posX][this->posY].food + 1;
	  this->food = food - 1;
	}
      else
	{
	  this->mapVision[this->posX][this->posY].mineral[element] =
	    this->mapVision[this->posX][this->posY].mineral[element] + 1;
	  this->mineral[element] = this->mineral[element] - 1;
	}
    }
}

bool					player::command::incantationCall()
{
  msend((char *)"Incantation\n");
  if (strcmp(playerReceive(), "Elevation underway") == 0)
    return (true);
  return (false);
}

char					*player::command::playerReceive()
{
  char					*str;
  std::regex				r_num("message.*");
  std::regex				r_num_fork("message [0-9], fork control");
  std::regex				r_num_incant("Current level [0-9]");
  std::cmatch				cm;

  str = mblock_recv();
  // std::cout << str << std::endl;
  while (std::regex_match(str, cm, r_num))
    {
      if (std::regex_match(str, cm, r_num))
	broadcastText("here");
      this->taskList.push(std::string(str));
      str = mrecv();
    }
  if (strcmp(str, "dead") == 0)
    exit(0);
  return (str);
}

// player::command&	player::command::operator=(command const & command)
// {
//   // this = command(command);
//   return (*this);
// }
