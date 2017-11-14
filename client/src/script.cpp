//
// script.cpp for script in /home/mag_d/rendu/PSU_2016_zappy/client/src
// 
// Made by david mag
// Login   <mag_d@epitech.net>
// 
// Started on  Sun Jul  2 14:02:23 2017 david mag
// Last update Sun Jul  2 20:00:58 2017 david mag
//

#include "client.h"
#include "player.hpp"

player::script::script(int x, int y) : command(x, y)
{

}

player::script::script(script const & script) : command(script)
{

}

player::script::~script()
{

}

void				player::script::takeParasite()
{
  look();
  while (this->getTile(this->getPosX(), this->getPosY()).mineral[0]
	 > player::prerequiIncantation[this->getElevation() - 1][0])
    this->takeObject("linemate", player::LINEMATE, false);
  while (this->getTile(this->getPosX(), this->getPosY()).mineral[1]
	 > player::prerequiIncantation[this->getElevation() - 1][1])
    this->takeObject("deraumere", player::DERAUMERE, false);
  while (this->getTile(this->getPosX(), this->getPosY()).mineral[2]
	 > player::prerequiIncantation[this->getElevation() - 1][2])
    this->takeObject("sibur", player::SIBUR, false);
  while (this->getTile(this->getPosX(), this->getPosY()).mineral[3]
	 > player::prerequiIncantation[this->getElevation() - 1][3])
    this->takeObject("mendiane", player::MENDIANE, false);
  while (this->getTile(this->getPosX(), this->getPosY()).mineral[4]
	 > player::prerequiIncantation[this->getElevation() - 1][4])
    this->takeObject("phiras", player::PHIRAS, false);
  while (this->getTile(this->getPosX(), this->getPosY()).mineral[5]
	 > player::prerequiIncantation[this->getElevation() - 1][5])
    this->takeObject("thystame", player::THYSTAME, false);
  while (this->getTile(this->getPosX(), this->getPosY()).food > 0)
    this->takeObject("food", player::THYSTAME, true);
}

void				player::script::setLevelObjects()
{
  look();
  while (this->getTile(this->getPosX(), this->getPosY()).mineral[0]
	 < player::prerequiIncantation[this->getElevation() - 1][0])
    this->setObject("linemate", player::LINEMATE, false);
  while (this->getTile(this->getPosX(), this->getPosY()).mineral[1]
	 < player::prerequiIncantation[this->getElevation() - 1][1])
      this->setObject("deraumere", player::DERAUMERE, false);
  while (this->getTile(this->getPosX(), this->getPosY()).mineral[2]
	 < player::prerequiIncantation[this->getElevation() - 1][2])
      this->setObject("sibur", player::SIBUR, false);
  while (this->getTile(this->getPosX(), this->getPosY()).mineral[3]
	 < player::prerequiIncantation[this->getElevation() - 1][3])
    this->setObject("mendiane", player::MENDIANE, false);
  while (this->getTile(this->getPosX(), this->getPosY()).mineral[4]
	 < player::prerequiIncantation[this->getElevation() - 1][4])
    this->setObject("phiras", player::PHIRAS, false);
  while (this->getTile(this->getPosX(), this->getPosY()).mineral[5]
	 < player::prerequiIncantation[this->getElevation() - 1][5])
    this->setObject("thystame", player::THYSTAME, false);
}

void				player::script::setIncantation()
{
  std::string			message;
  std::string			retn;
  int				count;
  
  count = 0;
  while (count != 2)
    {
      takeParasite();
      setLevelObjects();
      if (this->getTile(this->getPosX(), this->getPosY()).player
	  == player::prerequiIncantation[this->getElevation() - 1][6])
	{	
	  message = "I'm level ";
	  message += std::to_string(this->getElevation());
	  message += " and we're full.";
	  this->broadcastText(message);
	  if (count == 0)
	    {
	      if (this->incantationCall() == true)
		{
		  retn = this->playerReceive();
		  if (retn != "")
		    {
		      if (retn != "ko")
			{
			  this->setElevation(this->getElevation() + 1);
			  this->look();
			  return;
			}
		      else if (retn == "ko")
			return;
		    }
		}
	    }
	}
      else if (this->getTile(this->getPosX(), this->getPosY()).player
	       < prerequiIncantation[this->getElevation() - 1][6])
	{
	  message = "I'm level ";
	  message += std::to_string(this->getElevation());
	  message += " and I need ";
	  message += std::to_string(prerequiIncantation[this->getElevation() - 1][6] - 1);
	  message += " firends to Incant.";
	  broadcastText(message);
	  this->inventory();
	  if (this->getFood() < 20 && count != 1)
	    return;
	}
      else
	{
	  this->ejectPlayer();
	  this->inventory();
	  if (this->getFood() < 20 && count != 1)
	    return;
	}
    }
}

void				player::script::searchFood()
{
  int				i;

  i = 0;
  while (this->findFood() == NULL)
    {
      if (i >= this->getMapSizeX())
	{
	  i = 0;
	  this->turnLeft();
	  while (i < (this->getElevation() * 2) + 1)
	    {
	      this->forward();
	      i++;
	    }
	  this->turnLeft();
	  i = 0;
	}
      if (i % (this->getElevation() + 1) == 0)
	this->look();
      else
	{
	  this->forward();
	}
      i++;
    }
}

void				player::script::searchMineral(player::mineralList element)
{
  int				i;

  i = 0;
  while (this->findMineral(element) == NULL)
    {
      if (i >= this->getMapSizeX())
	{
	  i = 0;
	  this->turnLeft();
	  while (i < (this->getElevation() * 2) + 1)
	    {
	      this->forward();
	      i++;
	    }
	  this->turnLeft();
	  i = 0;
	}
      if (i % (this->getElevation() + 1) == 0)
	this->look();
      else
	{
	  this->forward();
	}
      i++;
    }
}

void				player::script::search()
{
  int				i;

  i = 0;
  while (this->findMineral((player::mineralList)0) == NULL &&
	 this->findMineral((player::mineralList)1) == NULL &&
	 this->findMineral((player::mineralList)2) == NULL &&
	 this->findMineral((player::mineralList)3) == NULL &&
	 this->findMineral((player::mineralList)4) == NULL &&
	 this->findMineral((player::mineralList)5) == NULL)
    {
      if (i >= this->getMapSizeX())
	{
	  i = 0;
	  this->turnLeft();
	  while (i < (this->getElevation() * 2) + 1)
	    {
	      this->forward();
	      i++;
	    }
	  this->turnLeft();
	  i = 0;
	}
      if (i % (this->getElevation() + 1) == 0)
	this->look();
      else
	{
	  this->forward();
	}
      i++;
    }
}

void				player::script::myGoTo(int x, int y)
{
  int				posX;
  int				posY;
  
  posX = this->getPosX();
  if (posX < x)
    this->setOriantation(player::EST);
  else if (posX > x)
    this->setOriantation(player::OUEST);
  while (posX != x)
    {
      this->forward();
      posX = this->getPosX();
    }
  posY = this->getPosY();
  if (posY < y)
    this->setOriantation(player::NORD);
  else if (posY > y)
    this->setOriantation(player::SUD);
  while (posY != y)
    {
      this->forward();
      posY = this->getPosY();
    }
}


void				player::script::doTask()
{
  std::string			task;
  // std::vector<std::string>	taskTab;
  
  task = this->taskList.front();
  this->taskList.pop();
  // taskTab = wordtab((char *)task.c_str(), ' ');
  // if (tasklist[0].size())
  //   radar(me);
}

void				player::script::gatherMineral()
{
  int				i;
  int				c;
  int				max;
  int				*pos;
  std::vector<std::string>	mlist;

  mlist.push_back(std::string("linemate"));
  mlist.push_back(std::string("deraumere"));
  mlist.push_back(std::string("sibur"));
  mlist.push_back(std::string("mendiane"));
  mlist.push_back(std::string("phiras"));
  mlist.push_back(std::string("thystame"));
  i = 0;
  while (i < 6)
    {
      c = 0;
      max = 0;
      while (c < (7 - this->getElevation()))
	{
	  max  = max + player::prerequiIncantation[c][i] + this->getElevation();
	  c++;
      
	}
      if (this->getMineral((player::mineralList)i) < max && (pos = this->findMineral((player::mineralList)i)) != NULL)
	{
	  myGoTo(pos[0], pos[1]);
	  this->takeObject(mlist[i], (player::mineralList)i, false);
	  delete pos;
	}
      i++;
    }
}

void				player::script::incantation()
{
  if (this->getMineral(player::LINEMATE) < player::prerequiIncantation[this->getElevation() - 1][player::LINEMATE] ||
      this->getMineral(player::DERAUMERE) < player::prerequiIncantation[this->getElevation() - 1][player::DERAUMERE] ||
      this->getMineral(player::SIBUR) < player::prerequiIncantation[this->getElevation() - 1][player::SIBUR] ||
      this->getMineral(player::MENDIANE) < player::prerequiIncantation[this->getElevation() - 1][player::MENDIANE] ||
      this->getMineral(player::PHIRAS) < player::prerequiIncantation[this->getElevation() - 1][player::PHIRAS] ||
      this->getMineral(player::THYSTAME) < player::prerequiIncantation[this->getElevation() - 1][player::THYSTAME] || this->getFood() < 20)
    return ;
  setIncantation();
}

const std::vector<std::string>	player::script::explode(const std::string& s, const char& c)
{
  std::string buff{""};
  std::vector<std::string> v;

  for(auto n:s)
    {
      if(n != c) buff+=n;
      else if(n == c && buff != "")
	{
	  v.push_back(buff);
	  buff = "";
	}
    }
  if(buff != "") v.push_back(buff);
  return v;
}

void				player::script::find()
{
  std::regex			rmsg("message ([0-9]), (.*)");
  std::cmatch			cm;
  std::vector<std::string>	tab;
  
  while (std::regex_match(this->taskList.front().c_str(), cm, rmsg))
    {
      tab = explode(cm[2], ' ');
      if (tab[0] == "myteam")
	{
	  if (cm[1] == "2" || cm[1] == "1" || cm[1] == "8")
	    this->forward();
	  else if (cm[1] == "3" || cm[1] == "4" || cm[1] == "5")
	    this->turnLeft();
	  else if (cm[1] == "6" || cm[1] == "7")
	    this->turnRight();
	}
    }
  this->taskList.pop();
}
