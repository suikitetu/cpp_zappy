//
// ai.cpp for ai in /home/mag_d/rendu/PSU_2016_zappy/client/src
// 
// Made by david mag
// Login   <mag_d@epitech.net>
// 
// Started on  Mon Jun 26 14:29:28 2017 david mag
// Last update Sun Jul  2 19:57:18 2017 david mag
//

#include "client.h"
#include "player.hpp"
  
// void			searchFood(player::command *me)
// {
//   int				i;

//   i = 0;
//   while (me->findFood() == NULL)
//     {
//       if (i >= me->getMapSizeX())
// 	{
// 	  i = 0;
// 	  me->turnLeft();
// 	  while (i < (me->getElevation() * 2) + 1)
// 	    {
// 	      me->forward();
// 	      i++;
// 	    }
// 	  me->turnLeft();
// 	  i = 0;
// 	}
//       if (i % (me->getElevation() + 1) == 0)
// 	me->look();
//       else
// 	{
// 	  me->forward();
// 	}
//       i++;
//     }
// }

// void				searchMineral(player::command *me, player::mineralList element)
// {
//   int				i;

//   i = 0;
//   while (me->findMineral(element) == NULL)
//     {
//       if (i >= me->getMapSizeX())
// 	{
// 	  i = 0;
// 	  me->turnLeft();
// 	  while (i < (me->getElevation() * 2) + 1)
// 	    {
// 	      me->forward();
// 	      i++;
// 	    }
// 	  me->turnLeft();
// 	  i = 0;
// 	}
//       if (i % (me->getElevation() + 1) == 0)
// 	me->look();
//       else
// 	{
// 	  me->forward();
// 	}
//       i++;
//     }
// }

// void				search(player::command *me)
// {
//   int				i;

//   i = 0;
//   while (me->findMineral((player::mineralList)0) == NULL &&
// 	 me->findMineral((player::mineralList)1) == NULL &&
// 	 me->findMineral((player::mineralList)2) == NULL &&
// 	 me->findMineral((player::mineralList)3) == NULL &&
// 	 me->findMineral((player::mineralList)4) == NULL &&
// 	 me->findMineral((player::mineralList)5) == NULL)
//     {
//       if (i >= me->getMapSizeX())
// 	{
// 	  i = 0;
// 	  me->turnLeft();
// 	  while (i < (me->getElevation() * 2) + 1)
// 	    {
// 	      me->forward();
// 	      i++;
// 	    }
// 	  me->turnLeft();
// 	  i = 0;
// 	}
//       if (i % (me->getElevation() + 1) == 0)
// 	me->look();
//       else
// 	{
// 	  me->forward();
// 	}
//       i++;
//     }
// }

// void				myGoTo(player::command *me, int x, int y)
// {
//   int				posX;
//   int				posY;
  
//   posX = me->getPosX();
//   if (posX < x)
//     me->setOriantation(player::EST);
//   else if (posX > x)
//     me->setOriantation(player::OUEST);
//   while (posX != x)
//     {
//       me->forward();
//       posX = me->getPosX();
//     }
//   posY = me->getPosY();
//   if (posY < y)
//     me->setOriantation(player::NORD);
//   else if (posY > y)
//     me->setOriantation(player::SUD);
//   while (posY != y)
//     {
//       me->forward();
//       posY = me->getPosY();
//     }
// }


// void				doTask(player::command *me)
// {
//   std::string			task;
//   // std::vector<std::string>	taskTab;
  
//   task = me->taskList.front();
//   me->taskList.pop();
//   // taskTab = wordtab((char *)task.c_str(), ' ');
//   // if (tasklist[0].size())
//   //   radar(me);
// }

// void				gatherMineral(player::command *me)
// {
//   int				i;
//   int				c;
//   int				max;
//   int				*pos;
//   std::vector<std::string>	mlist;

//   mlist.push_back(std::string("linemate"));
//   mlist.push_back(std::string("deraumere"));
//   mlist.push_back(std::string("sibur"));
//   mlist.push_back(std::string("mendiane"));
//   mlist.push_back(std::string("phiras"));
//   mlist.push_back(std::string("thystame"));
//   i = 0;
//   while (i < 6)
//     {
//       c = 0;
//       max = 0;
//       while (c < (7 - me->getElevation()))
// 	{
// 	  max  = max + player::prerequiIncantation[c][i] + me->getElevation();
// 	  c++;
      
// 	}
//       if (me->getMineral((player::mineralList)i) < max && (pos = me->findMineral((player::mineralList)i)) != NULL)
// 	{
// 	  myGoTo(me, pos[0], pos[1]);
// 	  me->takeObject(mlist[i], (player::mineralList)i, false);
// 	  delete pos;
// 	}
//       i++;
//     }
// }

// void				incantation(player::command *me)
// {
//   if (me->getMineral(player::LINEMATE) < player::prerequiIncantation[me->getElevation() - 1][player::LINEMATE] ||
//       me->getMineral(player::DERAUMERE) < player::prerequiIncantation[me->getElevation() - 1][player::DERAUMERE] ||
//       me->getMineral(player::SIBUR) < player::prerequiIncantation[me->getElevation() - 1][player::SIBUR] ||
//       me->getMineral(player::MENDIANE) < player::prerequiIncantation[me->getElevation() - 1][player::MENDIANE] ||
//       me->getMineral(player::PHIRAS) < player::prerequiIncantation[me->getElevation() - 1][player::PHIRAS] ||
//       me->getMineral(player::THYSTAME) < player::prerequiIncantation[me->getElevation() - 1][player::THYSTAME] || me->getFood() < 20)
//     {
//       std::cout << "test" << std::endl;
//       return ;
//     }
//   setIncantation(me);
// }

  // message += "incantation level ";
  // message += std::to_string(me->getElevation());
  // std::cout << message << std::endl;
  // me->broadcastText(message);
  // me->clean();
  // me->place();
  // me->incantation();
  // std::cout << message << std::endl;
  // while (std::regex_match(task.c_str(), cm, r_num_ok) == false || std::regex_match(task.c_str(), cm, r_num_ko) == false)
  //   {
  //     std::cout << message << std::endl;
  //     std::cout << task << std::endl;
  //     me->broadcastText(message);
  //     if (!me->taskList.empty())
  // 	{
  // 	  task = me->taskList.front();
  // 	  me->taskList.pop();
  // 	}
  //   }
  // if (std::regex_match(task.c_str(), cm, r_num_ok))
  //   me->setElevation(me->getElevation() + 1);

void				ai(int x, int y)
{
  player::script		*me = new player::script(x, y);
  bool				dead = false;
  int				*pos;
  
  while (dead == false)
    {
      // if (!me->taskList.empty())
      // 	me->doTask();
      me->gatherMineral();
      me->incantation();
      if (me->getFood() < 50 && (pos = me->findFood()) != NULL)
	{
	  me->myGoTo(pos[0], pos[1]);
	  me->takeObject("food", player::LINEMATE, true);
	  delete pos;
	}
      else if (me->getFood() < 100)
	me->searchFood();
      else
	me->search();
      me->inventory();
    }
  delete me;
}

  // const std::vector<std::string> explode(const std::string& s, const char& c)
  // {
  //   std::string buff{""};
  //   std::vector<std::string> v;

  //   for(auto n:s)
  //     {
  // 	if(n != c) buff+=n;
  // 	else if(n == c && buff != "")
  // 	  {
  // 	    v.push_back(buff);
  // 	    buff = "";
  // 	  }
  //     }
  //   if(buff != "") v.push_back(buff);
  //   return v;
  // }

  // void			find(player::command *me)
  // {
  //   std::regex		rmsg("message ([0-9]), (.*)");
  //   std::cmatch		cm;
  //   std::vector<std::string>	tab;
  
  //   while (std::regex_match(me->taskList.front().c_str(), cm, rmsg))
  //     {
  // 	tab = explode(cm[2], ' ');
  // 	if (tab[0] == "myteam")
  // 	  {
  // 	    if (cm[1] == "2" || cm[1] == "1" || cm[1] == "8")
  // 	      me->forward();
  // 	    else if (cm[1] == "3" || cm[1] == "4" || cm[1] == "5")
  // 	      me->turnLeft();
  // 	    else if (cm[1] == "6" || cm[1] == "7")
  // 	      me->turnRight();
  // 	  }
  //     }
  //   me->taskList.pop();
  // }
