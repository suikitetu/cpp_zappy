//
// draw.cpp for  in /home/doyon_e/rendu/semestre_4/PSU/PSU_2016_zappy/client_graph
// 
// Made by DOYON Etienne
// Login   <doyon_e@epitech.net>
// 
// Started on  Thu Jun 29 14:58:38 2017 DOYON Etienne
// Last update Sun Jul  2 19:33:51 2017 DOYON Etienne
//

#ifdef _MSC_VER
#pragma comment(lib, "lib/Irrlicht.lib")
#endif

#include <../lib/inc/irrlicht.h>
#include "graph.hpp"

static void	my_part_players(irr::video::IVideoDriver *driver,
			Map &mmap,
			irr::gui::IGUIEnvironment *guienv,
			int X, int Y, int square)
{
  int	i;
  int	XX;
  int	YY;

  XX = 0;
  while (++XX < 9)
    {
      YY = 0;
      while (++YY < 9)
	{
	  i = -1;
	  while ((unsigned int)++i != mmap.pl.list.size())
	    {
	      if (mmap.pl.list[i].X == ((XX + mmap.MappingX - 1 + mmap.X) % mmap.X) && mmap.pl.list[i].Y == ((YY + mmap.MappingY - 1) + mmap.Y) % mmap.Y)
		{
		  if (mmap.pl.list[i].orient == 1)
		    driver->draw2DImage(mmap.player3,
					irr::core::position2d<irr::s32>(420 + ((3 + square) * XX) + mmap.pl.list[i].POSX, (square + 3) * YY + mmap.pl.list[i].POSY),
					irr::core::rect<irr::s32>(0, 0, 40, 50),
					0,
					irr::video::SColor(255, 255, 255, 255),
					true);
		  else if (mmap.pl.list[i].orient == 2)
		    driver->draw2DImage(mmap.player4,
					irr::core::position2d<irr::s32>(420 + ((3 + square) * XX) + mmap.pl.list[i].POSX, (square + 3) * YY + mmap.pl.list[i].POSY),
					irr::core::rect<irr::s32>(0, 0, 50, 50),
					0,
					irr::video::SColor(255, 255, 255, 255),
					true);
		  else if (mmap.pl.list[i].orient == 3)
		    driver->draw2DImage(mmap.player1,
					irr::core::position2d<irr::s32>(420 + ((3 + square) * XX) + mmap.pl.list[i].POSX, (square + 3) * YY + mmap.pl.list[i].POSY),
					irr::core::rect<irr::s32>(0, 0, 40, 45),
					0,
					irr::video::SColor(255, 255, 255, 255),
					true);
		  else
		    driver->draw2DImage(mmap.player2,
					irr::core::position2d<irr::s32>(420 + ((3 + square) * XX) + mmap.pl.list[i].POSX, (square + 3) * YY + mmap.pl.list[i].POSY),
					irr::core::rect<irr::s32>(0, 0, 50, 50),
					0,
					irr::video::SColor(255, 255, 255, 255),
					true);
		}
	    }
	}
    }
  XX = 0;
  while (++XX < 9)
    {
      YY = 0;
      while (++YY < 9)
	{
	  i = -1;
	  while ((unsigned int)++i != mmap.pl.list2.size())
	    {
	      if (mmap.pl.list2[i].X == ((XX + mmap.MappingX - 1 + mmap.X) % mmap.X) && mmap.pl.list2[i].Y == ((YY + mmap.MappingY - 1) + mmap.Y) % mmap.Y)
		driver->draw2DImage(mmap.egg,
				    irr::core::position2d<irr::s32>(420 + ((3 + square) * XX), (square + 3) * YY),
				    irr::core::rect<irr::s32>(0, 0, 40, 50),
				    0,
				    irr::video::SColor(255, 255, 255, 255),
				    true);
	    }
	}
    }
}

void	my_doc(irr::video::IVideoDriver *driver,
	       Map &mmap,
	       irr::gui::IGUIEnvironment *guienv,
	       const wchar_t *to_print)
{
  driver->draw2DImage(mmap.legend,
		      irr::core::position2d<irr::s32>(50, 500),
		      irr::core::rect<irr::s32>(0, 0, 300, 600),
		      0,
		      irr::video::SColor(255, 255, 255, 255),
		      true);
  guienv->addStaticText(to_print,
			irr::core::rect<irr::s32>(1420,210,1680,306), true, true, 0, -1, true);
}

void	my_draw2(irr::video::IVideoDriver *driver,
		 Map &mmap,
		 irr::gui::IGUIEnvironment *guienv,
		 int square, int X, int Y)
{
  int   XX;
  int   YY;

  XX = 0;
  while (++XX < 9)
    {
      YY = 0;
      while (++YY < 9)
	driver->draw2DImage(mmap.up,
			    irr::core::position2d<irr::s32>(420 + (square + 3) * YY, 0),
			    irr::core::rect<irr::s32>(0, 0, 100, 100),
			    0,
			    irr::video::SColor(255, 255, 255, 255),
			    true);
      YY = 0;
      while (++YY < 9)
	{
	  driver->draw2DImage(mmap.left,
			      irr::core::position2d<irr::s32>(420, (square + 3) * YY),
			      irr::core::rect<irr::s32>(0, 0, 100, 100),
			      0,
			      irr::video::SColor(255, 255, 255, 255),
			      true);
	  driver->draw2DImage(mmap.grass,
			      irr::core::position2d<irr::s32>(420 + ((3 + square) * XX), (square + 3) * YY),
			      irr::core::rect<irr::s32>(0, 0, square, square),
			      0,
			      irr::video::SColor(255, 255, 255, 255),
			      true);
          if (mmap.entire_map[(XX + mmap.MappingX - 1 + mmap.X) % mmap.X][(YY + mmap.MappingY - 1 + mmap.Y) % mmap.Y]->Getfood() == 1)
	    driver->draw2DImage(mmap.food,
				irr::core::position2d<irr::s32>(420 + ((3 + square) * XX), (square + 3) * YY + 5),
				irr::core::rect<irr::s32>(0, 0, 85, 73),
				0,
				irr::video::SColor(255, 255, 255, 255),
				true);
	  else if (mmap.entire_map[(XX + mmap.MappingX - 1 + mmap.X) % mmap.X][(YY + mmap.MappingY - 1 + mmap.Y) % mmap.Y]->Getfood() > 1)
	    driver->draw2DImage(mmap.foods,
				irr::core::position2d<irr::s32>(420 + ((3 + square) * XX), (square + 3) * YY + 5),
				irr::core::rect<irr::s32>(0, 0, 86, 75),
				0,
				irr::video::SColor(255, 255, 255, 255),
				true);
	  driver->draw2DImage(mmap.right,
			      irr::core::position2d<irr::s32>(420 + ((3 + square) * 9), (square + 3) * YY),
			      irr::core::rect<irr::s32>(0, 0, 100, 100),
			      0,
			      irr::video::SColor(255, 255, 255, 255),
			      true);
	}
      driver->draw2DImage(mmap.down,
			  irr::core::position2d<irr::s32>(420 + ((3 + square) * XX), (square + 3) * YY),
			  irr::core::rect<irr::s32>(0, 0, 100, 100),
			  0,
			  irr::video::SColor(255, 255, 255, 255),
			  true);
    }
  my_part_players(driver, mmap, guienv, X, Y, square);
}

void	my_draw(irr::video::IVideoDriver *driver,
		Map &mmap,
		irr::gui::IGUIEnvironment *guienv,
		int square, int X, int Y)
{
  int	XX;
  int	YY;

  XX = 0;
  while (++XX < 9)
    {
      YY = 0;
      while (++YY < 9)
	driver->draw2DImage(mmap.up,
			    irr::core::position2d<irr::s32>(420 + (square + 3) * YY, 0),
			    irr::core::rect<irr::s32>(0, 0, 100, 100),
			    0,
			    irr::video::SColor(255, 255, 255, 255),
			    true);
      YY = 0;
      while (++YY < 9)
	{
	  driver->draw2DImage(mmap.left,
			      irr::core::position2d<irr::s32>(420, (square + 3) * YY),
			      irr::core::rect<irr::s32>(0, 0, 100, 100),
			      0,
			      irr::video::SColor(255, 255, 255, 255),
			      true);
	  driver->draw2DImage(mmap.dirt,
			      irr::core::position2d<irr::s32>(420 + ((3 + square) * XX), (square + 3) * YY),
			      irr::core::rect<irr::s32>(0, 0, square, square),
			      0,
			      irr::video::SColor(255, 255, 255, 255),
			      true);
	  if (mmap.entire_map[(XX + mmap.MappingX - 1 + mmap.X) % mmap.X][(YY + mmap.MappingY - 1 + mmap.Y) % mmap.Y]->Getlinemate() == 1)
	    driver->draw2DImage(mmap.linemate,
				irr::core::position2d<irr::s32>(420 + ((3 + square) * XX), (square + 3) * YY),
				irr::core::rect<irr::s32>(0, 0, mmap.minX, mmap.minY),
				0,
				irr::video::SColor(255, 255, 255, 255),
				true);
	  else if (mmap.entire_map[(XX + mmap.MappingX - 1 + mmap.X) % mmap.X][(YY + mmap.MappingY - 1 + mmap.Y) % mmap.Y]->Getlinemate() > 1)
	    driver->draw2DImage(mmap.linemates,
				irr::core::position2d<irr::s32>(420 + ((3 + square) * XX), (square + 3) * YY),
				irr::core::rect<irr::s32>(0, 0, 54, 33),
				0,
				irr::video::SColor(255, 255, 255, 255),
				true);
	  if (mmap.entire_map[(XX + mmap.MappingX - 1 + mmap.X) % mmap.X][(YY + mmap.MappingY - 1 + mmap.Y) % mmap.Y]->Getderaumere() == 1)
	    driver->draw2DImage(mmap.deraumere,
				irr::core::position2d<irr::s32>(420 + ((3 + square) * XX), (square + 3) * YY + mmap.minY),
				irr::core::rect<irr::s32>(0, 0, mmap.minX, mmap.minY),
				0,
				irr::video::SColor(255, 255, 255, 255),
				true);
          else if (mmap.entire_map[(XX + mmap.MappingX - 1 + mmap.X) % mmap.X][(YY + mmap.MappingY - 1 + mmap.Y) % mmap.Y]->Getderaumere() > 1)
	    driver->draw2DImage(mmap.deraumeres,
				irr::core::position2d<irr::s32>(420 + ((3 + square) * XX), (square + 3) * YY + mmap.minY),
				irr::core::rect<irr::s32>(0, 0, 54, 33),
				0,
				irr::video::SColor(255, 255, 255, 255),
				true);
	  if (mmap.entire_map[(XX + mmap.MappingX - 1 + mmap.X) % mmap.X][(YY + mmap.MappingY - 1 + mmap.Y) % mmap.Y]->Getsibur() == 1)
	    driver->draw2DImage(mmap.sibur,
				irr::core::position2d<irr::s32>(420 + ((3 + square) * XX), (square + 3) * YY + (mmap.minY * 2)),
				irr::core::rect<irr::s32>(0, 0, mmap.minX, mmap.minY),
				0,
				irr::video::SColor(255, 255, 255, 255),
				true);
          else if (mmap.entire_map[(XX + mmap.MappingX - 1 + mmap.X) % mmap.X][(YY + mmap.MappingY - 1 + mmap.Y) % mmap.Y]->Getsibur() > 1)
	    driver->draw2DImage(mmap.siburs,
				irr::core::position2d<irr::s32>(420 + ((3 + square) * XX), (square + 3) * YY + (mmap.minY * 2)),
				irr::core::rect<irr::s32>(0, 0, 54, 33),
				0,
				irr::video::SColor(255, 255, 255, 255),
				true);
	  if (mmap.entire_map[(XX + mmap.MappingX - 1 + mmap.X) % mmap.X][(YY + mmap.MappingY - 1 + mmap.Y) % mmap.Y]->Getmendiane() == 1)
	    driver->draw2DImage(mmap.mendiane,
				irr::core::position2d<irr::s32>(420 + ((3 + square) * XX + mmap.minX), (square + 3) * YY + (mmap.minY)),
				irr::core::rect<irr::s32>(0, 0, mmap.minX, mmap.minY),
				0,
				irr::video::SColor(255, 255, 255, 255),
				true);
	  else if (mmap.entire_map[(XX + mmap.MappingX - 1 + mmap.X) % mmap.X][(YY + mmap.MappingY - 1 + mmap.Y) % mmap.Y]->Getmendiane() > 1)
	    driver->draw2DImage(mmap.mendianes,
				irr::core::position2d<irr::s32>(420 + ((3 + square) * XX + mmap.minX), (square + 3) * YY + (mmap.minY)),
				irr::core::rect<irr::s32>(0, 0, 54, 33),
				0,
				irr::video::SColor(255, 255, 255, 255),
				true);
	  if (mmap.entire_map[(XX + mmap.MappingX - 1 + mmap.X) % mmap.X][(YY + mmap.MappingY - 1 + mmap.Y) % mmap.Y]->Getthystame() == 1)
	    driver->draw2DImage(mmap.thystame,
				irr::core::position2d<irr::s32>(420 + ((3 + square) * XX + mmap.minX), (square + 3) * YY + (mmap.minY * 2)),
				irr::core::rect<irr::s32>(0, 0, mmap.minX, mmap.minY),
				0,
				irr::video::SColor(255, 255, 255, 255),
				true);
	  else if (mmap.entire_map[(XX + mmap.MappingX - 1 + mmap.X) % mmap.X][(YY + mmap.MappingY - 1 + mmap.Y) % mmap.Y]->Getthystame() > 1)
	    driver->draw2DImage(mmap.thystames,
				irr::core::position2d<irr::s32>(420 + ((3 + square) * XX + mmap.minX), (square + 3) * YY + (mmap.minY * 2)),
				irr::core::rect<irr::s32>(0, 0, 54, 33),
				0,
				irr::video::SColor(255, 255, 255, 255),
				true);
          if (mmap.entire_map[(XX + mmap.MappingX - 1 + mmap.X) % mmap.X][(YY + mmap.MappingY - 1 + mmap.Y) % mmap.Y]->Getphiras() == 1)
	    driver->draw2DImage(mmap.phiras,
				irr::core::position2d<irr::s32>(420 + ((3 + square) * XX + mmap.minX), (square + 3) * YY),
				irr::core::rect<irr::s32>(0, 0, mmap.minX, mmap.minY),
				0,
				irr::video::SColor(255, 255, 255, 255),
				true);
	  else if (mmap.entire_map[(XX + mmap.MappingX - 1 + mmap.X) % mmap.X][(YY + mmap.MappingY - 1 + mmap.Y) % mmap.Y]->Getphiras() > 1)
	    driver->draw2DImage(mmap.phirass,
				irr::core::position2d<irr::s32>(420 + ((3 + square) * XX + mmap.minX), (square + 3) * YY),
				irr::core::rect<irr::s32>(0, 0, 54, 33),
				0,
				irr::video::SColor(255, 255, 255, 255),
				true);
	  driver->draw2DImage(mmap.right,
			      irr::core::position2d<irr::s32>(420 + ((3 + square) * 9), (square + 3) * YY),
			      irr::core::rect<irr::s32>(0, 0, 100, 100),
			      0,
			      irr::video::SColor(255, 255, 255, 255),
			      true);
	}
      driver->draw2DImage(mmap.down,
			  irr::core::position2d<irr::s32>(420 + ((3 + square) * XX), (square + 3) * YY),
			  irr::core::rect<irr::s32>(0, 0, 100, 100),
			  0,
			  irr::video::SColor(255, 255, 255, 255),
			  true);
    }
  my_part_players(driver, mmap, guienv, X, Y, square);
}
