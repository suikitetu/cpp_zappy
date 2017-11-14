/*
** graph.h for  in /home/doyon_e/rendu/semestre_4/PSU/PSU_2016_zappy/client_graph
** 
** Made by DOYON Etienne
** Login   <doyon_e@epitech.net>
** 
** Started on  Wed Jun 21 11:45:09 2017 DOYON Etienne
// Last update Sun Jul  2 21:10:10 2017 DOYON Etienne
*/

#ifndef _MY_GRAPH_HPP_
# define _MY_GRAPH_HPP_

#ifdef _MSC_VER
#pragma comment(lib, "lib/Irrlicht.lib")
#endif

#include <../lib/inc/irrlicht.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "player.hpp"
#include "Event.hpp"

class	Map_case
{
private:
  int	food;
  int	linemate;
  int	deraumere;
  int	sibur;
  int	mendiane;
  int	phiras;
  int	thystame;
public:
  Map_case();
  Map_case(const char *content);
  Map_case(const Map_case &thus);
  ~Map_case();

  void	SetFood(const int nb);
  void	SetLinemate(const int nb);
  void	SetDeraumere(const int nb);
  void	SetSibur(const int nb);
  void	SetMendiane(const int nb);
  void	SetPhiras(const int nb);
  void	SetThystame(const int nb);
  int	Getfood() const;
  int	Getlinemate() const;
  int	Getderaumere() const;
  int	Getsibur() const;
  int	Getmendiane() const;
  int	Getphiras() const;
  int	Getthystame() const;
};

class	Map
{
private:
  int	time_unit;
  int	tmp;
  std::vector<std::string>	teams;
public:
  Map();
  Map(irr::video::IVideoDriver *driver);
  ~Map();

  void	tna(char *&str);
  void  cmd(char *&str, irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *gui);
  void	bct(char *&str);
  void	dimension(char *&str);
  void	new_selection(int X, int Y);
  void	unselect();
  bool	mv_cam(MyEventReceiver receiver, bool press);

  int	button;
  int	MappingX;
  int	MappingY;
  int	X;
  int	Y;
  int	minX;
  int	minY;

  Player_list		pl;

  irr::video::ITexture  *grass;
  irr::video::ITexture  *dirt;
  irr::video::ITexture  *down;
  irr::video::ITexture  *up;
  irr::video::ITexture  *right;
  irr::video::ITexture	*left;
  irr::video::ITexture  *linemate;
  irr::video::ITexture	*linemates;
  irr::video::ITexture  *thystame;
  irr::video::ITexture  *thystames;
  irr::video::ITexture  *deraumere;
  irr::video::ITexture  *deraumeres;
  irr::video::ITexture  *player1;
  irr::video::ITexture  *player2;
  irr::video::ITexture  *player3;
  irr::video::ITexture  *player4;
  irr::video::ITexture  *mendiane;
  irr::video::ITexture  *mendianes;
  irr::video::ITexture  *phiras;
  irr::video::ITexture  *phirass;
  irr::video::ITexture  *sibur;
  irr::video::ITexture  *siburs;
  irr::video::ITexture  *foods;
  irr::video::ITexture  *food;
  irr::video::ITexture  *legend;
  irr::video::ITexture  *egg;
  
  std::vector<std::vector <Map_case *> >  entire_map;
};

void	my_draw(irr::video::IVideoDriver *driver,
		Map &mmap,
		irr::gui::IGUIEnvironment *guienv,
		int square, int X, int Y);
void	my_draw2(irr::video::IVideoDriver *driver,
		 Map &mmap,
		 irr::gui::IGUIEnvironment *guienv,
		 int square, int X, int Y);
void	my_doc(irr::video::IVideoDriver *driver,
	       Map &mmap,
	       irr::gui::IGUIEnvironment *guienv,
	       const wchar_t *to_print);
wchar_t *my_stradd(wchar_t *s1, const char *s2);

#endif /*!_MY_GRAPH_HPP_*/
