//
// graph.cpp for  in /home/doyon_e/rendu/semestre_4/PSU/PSU_2016_zappy/client_graph
// 
// Made by DOYON Etienne
// Login   <doyon_e@epitech.net>
// 
// Started on  Wed Jun 21 11:57:14 2017 DOYON Etienne
// Last update Sun Jul  2 21:10:41 2017 DOYON Etienne
//

#ifdef _MSC_VER
#pragma comment(lib, "lib/Irrlicht.lib")
#endif

#include <../lib/inc/irrlicht.h>
#include "graph.hpp"

Map_case::Map_case()
{
  this->food = 0;
  this->linemate = 0;
  this->deraumere = 0;
  this->sibur = 0;
  this->mendiane = 0;
  this->phiras = 0;
  this->thystame = 0;
}

Map_case::Map_case(const char *content)
{
  std::stringstream	my_value(content);
  std::string		tmp;

  my_value >> tmp;
  if (tmp != "bct")
    {
      std::cout << "Hey ! Case format not recognized !" << std::endl;
      exit (-1);
    }
  my_value >> tmp;
  my_value >> tmp;
  my_value >> tmp;
  this->food = std::stoi(tmp);
  my_value >> tmp;
  this->linemate = std::stoi(tmp);
  my_value >> tmp;
  this->deraumere = std::stoi(tmp);
  my_value >> tmp;
  this->sibur = std::stoi(tmp);
  my_value >> tmp;
  this->mendiane = std::stoi(tmp);
  my_value >> tmp;
  this->phiras = std::stoi(tmp);
  my_value >> tmp;
  this->thystame = std::stoi(tmp);
}

Map_case::Map_case(const Map_case &thus)
{
  this->food = thus.Getfood();
  this->linemate = thus.Getlinemate();
  this->deraumere = thus.Getderaumere();
  this->sibur = thus.Getsibur();
  this->mendiane = thus.Getmendiane();
  this->phiras = thus.Getphiras();
  this->thystame = thus.Getthystame();
}

Map_case::~Map_case()
{
}

void  Map_case::SetFood(const int nb)
{
  this->food = nb;
}

void  Map_case::SetLinemate(const int nb)
{
  this->linemate = nb;
}

void  Map_case::SetDeraumere(const int nb)
{
  this->deraumere = nb;
}

void  Map_case::SetSibur(const int nb)
{
  this->sibur = nb;
}

void  Map_case::SetMendiane(const int nb)
{
  this->mendiane = nb;
}

void  Map_case::SetPhiras(const int nb)
{
  this->phiras = nb;
}

void  Map_case::SetThystame(const int nb)
{
  this->thystame = nb;
}

int	Map_case::Getfood() const
{
  return (this->food);
}

int	Map_case::Getlinemate() const
{
  return (this->linemate);
}

int	Map_case::Getderaumere() const
{
  return (this->deraumere);
}

int	Map_case::Getsibur() const
{
  return (this->sibur);
}

int	Map_case::Getmendiane() const
{
  return (this->mendiane);
}

int	Map_case::Getphiras() const
{
  return (this->phiras);
}

int	Map_case::Getthystame() const
{
  return (this->thystame);
}

Map::Map()
{
  this->button = 1;
  this->MappingX = this->MappingY = 0;
}

Map::Map(irr::video::IVideoDriver *driver)
{
  this->button = 1;
  this->legend = driver->getTexture("client_graph/ressources/Legend.png");
  this->food = driver->getTexture("client_graph/ressources/food.png");
  this->foods = driver->getTexture("client_graph/ressources/foods.png");
  this->grass =  driver->getTexture("client_graph/ressources/Grass.png");
  this->dirt = driver->getTexture("client_graph/ressources/dirt.png");
  this->linemate = driver->getTexture("client_graph/ressources/linemate_28.png");
  this->linemates = driver->getTexture("client_graph/ressources/linemate_sac.png");
  this->thystame =  driver->getTexture("client_graph/ressources/thystame_28.png");
  this->thystames =  driver->getTexture("client_graph/ressources/thystame_sac.png");
  this->deraumere =  driver->getTexture("client_graph/ressources/deraumere_28.png");
  this->deraumeres =  driver->getTexture("client_graph/ressources/deraumere_sac.png");
  this->mendiane =  driver->getTexture("client_graph/ressources/mendiane_28.png");
  this->mendianes =  driver->getTexture("client_graph/ressources/mendiane_sac.png");
  this->phiras =  driver->getTexture("client_graph/ressources/phiras_28.png");
  this->player1 = driver->getTexture("client_graph/ressources/player1.png");
  this->player2 = driver->getTexture("client_graph/ressources/player2.png");
  this->player3 = driver->getTexture("client_graph/ressources/player3.png");
  this->player4 = driver->getTexture("client_graph/ressources/player4.png");
  this->phirass =  driver->getTexture("client_graph/ressources/phiras_sac.png");
  this->sibur =  driver->getTexture("client_graph/ressources/sibur_28.png");
  this->siburs =  driver->getTexture("client_graph/ressources/sibur_sac.png");
  this->right = driver->getTexture("client_graph/ressources/arrow_right.png");
  this->left = driver->getTexture("client_graph/ressources/arrow_left.png");
  this->up = driver->getTexture("client_graph/ressources/arrow_up.png");
  this->down = driver->getTexture("client_graph/ressources/arrow_down.png");
  this->egg = driver->getTexture("client_graph/ressources/Egg.png");
  this->MappingX = this->MappingY = -1;
  this->minX = 47;
  this->minY = 28;
  this->tmp = 60;
}

Map::~Map()
{
}

void	Map::dimension(char *&str)
{
  std::stringstream	my_value(str);
  int	X;
  int	Y;
  int	i;
  int	ii;
  Map_case	*c;
  std::string	tmp;

  my_value >> tmp;
  my_value >> tmp;
  X = std::stoi(tmp);
  my_value >> tmp;
  Y = std::stoi(tmp);
  i = -1;
  this->entire_map.reserve(X + 1);
  while (++i != X)
    {
      std::vector<Map_case *>       vec;
      ii = -1;
      vec.reserve(Y + 1);
      while (++ii != Y)
	{
	  c = new Map_case;
	  vec.push_back(c);
	}
      this->entire_map.push_back(vec);
    }
  this->MappingX = X * 1000;
  this->MappingY = Y * 1000;
  this->X = X;
  this->Y = Y;
}

void	Map::bct(char *&str)
{
  std::stringstream	my_value(str);
  std::string		tmp;
  int			X;
  int			Y;

  my_value >> tmp;
  my_value >> tmp;
  X = std::stoi(tmp);
  my_value >> tmp;
  Y = std::stoi(tmp);
  my_value >> tmp;
  this->entire_map[X][Y]->SetFood(std::stoi(tmp));
  my_value >> tmp;
  this->entire_map[X][Y]->SetLinemate(std::stoi(tmp));
  my_value >> tmp;
  this->entire_map[X][Y]->SetDeraumere(std::stoi(tmp));
  my_value >> tmp;
  this->entire_map[X][Y]->SetSibur(std::stoi(tmp));
  my_value >> tmp;
  this->entire_map[X][Y]->SetMendiane(std::stoi(tmp));
  my_value >> tmp;
  this->entire_map[X][Y]->SetPhiras(std::stoi(tmp));
  my_value >> tmp;
  this->entire_map[X][Y]->SetThystame(std::stoi(tmp));
}

void	Map::tna(char *&str)
{
  std::stringstream     my_value(str);
  std::string           tmp;

  my_value >> tmp;
  my_value >> tmp;
  this->teams.push_back(tmp);
}

void	Map::new_selection(int X, int Y)
{
  int	XX;
  int	YY;
  int	i;

  XX = ((X - 420) / 99 + this->MappingX - 1 + this->X) % this->X;
  YY = (Y / 99 + this->MappingY + this->Y) % this->Y;
  i = -1;
  while ((unsigned int)++i != this->pl.list.size())
    {
      if (this->pl.list[i].X == XX && this->pl.list[i].Y == YY - 1)
	this->pl.list[i].selected = 1;
    }
}

void  Map::cmd(char *&str, irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *gui)
{
  std::stringstream     my_value(str);
  std::string		tmp;

  my_value >> tmp;
  if (tmp == "msz")
    this->dimension(str);
  else if (tmp == "tna")
    this->tna(str);
  else if (tmp == "sgt")
    {
      my_value >> tmp;
      this->time_unit = std::stoi(tmp);
    }
  else if (tmp == "bct")
    this->bct(str);
  else if (tmp == "pnw")
    this->pl.add_list(str);
  else if (tmp == "ppo")
    this->pl.move_player(str, this);
  else if (tmp == "plv")
    this->pl.levelup(str);
  else if (tmp == "pdi")
    this->pl.kys(str);
  else if (tmp == "enw")
    this->pl.add_list2(str);
  else if (tmp == "eht")
    this->pl.rdy(str);
  else if (tmp == "ebo" || tmp == "edi")
    this->pl.die_fcking_egg(str);
  else if (tmp == "seg")
    {
      my_value >> tmp;
      std::cout << "END OF THE GAME ! The team " << tmp << " is the winner !" << std::endl;
      exit(1);
    }
  else if (tmp == "pbc")
    {
      my_value >> tmp;
      my_value >> tmp;
      std::wstring wsTmp(tmp.begin(), tmp.end());
      gui->addStaticText(wsTmp.c_str(),
			 irr::core::rect<irr::s32>(50,50,200,200), true, true, 0, -1, true);
    }
}

void	Map::unselect()
{
  int	i = -1;

  while ((unsigned int)++i != this->pl.list.size())
    {
      this->pl.list[i].selected = 0;
    }
}

bool	Map::mv_cam(MyEventReceiver receiver, bool press)
{
  if(receiver.IsKeyDown(irr::KEY_LEFT))
    {
      this->tmp--;
      if (press == false || tmp < 0)
	{
	  press = true;
	  this->MappingX--;
	}
    }
  else if(receiver.IsKeyDown(irr::KEY_RIGHT))
    {
      this->tmp--;
      if (press == false || tmp < 0)
	{
	  press = true;
	  this->MappingX++;
	}
    }
  else if(receiver.IsKeyDown(irr::KEY_UP))
    {
      this->tmp--;
      if (press == false || tmp < 0)
	{
	  press = true;
	  this->MappingY--;
	}
    }
  else if(receiver.IsKeyDown(irr::KEY_DOWN))
    {
      this->tmp--;
      if (press == false || tmp < 0)
	{
	  press = true;
	  this->MappingY++;
	}
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_Q))
    {
      this->tmp--;
      if (press == false || tmp < 0)
	{
	  press = true;
	  this->unselect();
	}
    }
  else
    {
      tmp = 60;
      press = false;
    }
  return (press);
}
