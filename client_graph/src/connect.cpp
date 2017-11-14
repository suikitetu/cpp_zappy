/*
** connect.cpp for PSU_2016_zappy
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Sun Jul 02 16:21:49 2017 Gauthier Harnisch
** Last update	Sun Jul 02 16:21:53 2017 Gauthier Harnisch
*/


#ifdef _MSC_VER
#pragma comment(lib, "lib/Irrlicht.lib")
#endif

#include <iostream>
#include <fstream>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <string>
#include <unistd.h>
#include <../lib/inc/irrlicht.h>
#include "client.h"
#include "graph.hpp"

static void	print_usage()
{
  std::cout << "USAGE: ./zappy_graph -p port -h machine" << std::endl;
  std::cout << "\tport\tis the port number" << std::endl;
  std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
  exit(1);
}

static void	my_graph(t_client *cl)
{
  int	map = 0;
  bool	press = false;
  char	*buff;
  MyEventReceiver receiver;
  irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL,
						  irr::core::dimension2d<irr::u32>(1920, 1080),
						  32, false, true, true, &receiver);
  irr::video::IVideoDriver* driver = device->getVideoDriver();
  irr::scene::ISceneManager *sceneManager = device->getSceneManager();
  irr::gui::IGUIEnvironment *gui = sceneManager->getGUIEnvironment();
  irr::gui::IGUIButton *Foo_button = gui->addButton(irr::core::rect<irr::s32>(100, 295, 300, 370),
						     0, -1, L"");
  irr::gui::IGUIButton *Res_button = gui->addButton(irr::core::rect<irr::s32>(100, 375, 300, 450),
						    0, -1, L"");
  int	X;
  int	Y;
  Map   *mmap = new Map(driver);
  Res_button->setImage(mmap->dirt);
  Foo_button->setImage(mmap->grass);
  std::wstring	test = L"Ca serait fun";

  while (device->run())
    {
      if (receiver.selectedX > 520 && receiver.selectedX < 1300 && receiver.selectedY > 100 && receiver.selectedY < 880)
	{
	  mmap->new_selection(receiver.selectedX, receiver.selectedY);
	  receiver.selectedX = receiver.selectedY = -1;
	}
      X = receiver.getmouseX();
      Y = receiver.getmouseY();
      test.clear();
      if (X < 520 || Y < 100 || X > 1300 || Y > 880)
	test.append(L"No case selected");
      else
	{
	  test.append(L"Case pointed : [");
	  test.append(std::to_wstring(((X - 420) / 99 + mmap->MappingX - 1 + mmap->X) % mmap->X));
	  test.append(L";");
	  test.append(std::to_wstring((Y / 99 + mmap->MappingY + mmap->Y) % mmap->Y));
	  test.append(L"]\nLinemate : ");
	  test.append(std::to_wstring(mmap->entire_map[((X - 420) / 99 + mmap->MappingX - 1 + mmap->X) % mmap->X][(Y / 99 + mmap->MappingY - 1 + mmap->Y) % mmap->Y]->Getlinemate()));
	  test.append(L"\nDeraumere : ");
	  test.append(std::to_wstring(mmap->entire_map[((X - 420) / 99 + mmap->MappingX - 1 + mmap->X) % mmap->X][(Y / 99 + mmap->MappingY - 1 + mmap->Y) % mmap->Y]->Getderaumere()));
          test.append(L"\nSibur : ");
	  test.append(std::to_wstring(mmap->entire_map[((X - 420) / 99 + mmap->MappingX - 1 + mmap->X) % mmap->X][(Y / 99 + mmap->MappingY - 1 + mmap->Y) % mmap->Y]->Getsibur()));
	  test.append(L"\nPhiras : ");
	  test.append(std::to_wstring(mmap->entire_map[((X - 420) / 99 + mmap->MappingX - 1 + mmap->X) % mmap->X][(Y / 99 + mmap->MappingY - 1 + mmap->Y) % mmap->Y]->Getphiras()));
	  test.append(L"\nMendiane : ");
	  test.append(std::to_wstring(mmap->entire_map[((X - 420) / 99 + mmap->MappingX - 1 + mmap->X) % mmap->X][(Y / 99 + mmap->MappingY - 1 + mmap->Y) % mmap->Y]->Getmendiane()));
          test.append(L"\nThystame : ");
	  test.append(std::to_wstring(mmap->entire_map[((X - 420) / 99 + mmap->MappingX - 1 + mmap->X) % mmap->X][(Y / 99 + mmap->MappingY - 1 + mmap->Y) % mmap->Y]->Getthystame()));
	  test.append(L"\nFood : ");
	  test.append(std::to_wstring(mmap->entire_map[((X - 420) / 99 + mmap->MappingX - 1 + mmap->X) % mmap->X][(Y / 99 + mmap->MappingY - 1 + mmap->Y) % mmap->Y]->Getfood()));
	}
      driver->beginScene(true, true,
			 irr::video::SColor(255, 0, 0, 0));
      buff = mrecv();
      if (buff != NULL)
	{
	  if (std::string(buff) == std::string("WELCOME") && map == 0)
	    map = msend((char *)"GRAPHIC\n");
	  else if (map != 0)
	    mmap->cmd(buff, driver, gui);
	}
      if (mmap->MappingX != -1 && mmap->button == 1)
	my_draw(driver, *mmap, gui, 95, mmap->X, mmap->Y);
      else if (mmap->MappingX != -1 && mmap->button == 2)
	my_draw2(driver, *mmap, gui, 95, mmap->X, mmap->Y);
      my_doc(driver, *mmap, gui, test.c_str());
      sceneManager->drawAll();
      press = mmap->mv_cam(receiver, press);
      gui->drawAll();
      if (Foo_button->isPressed() == true)
	mmap->button = 2;
      else if (Res_button->isPressed() == true)
	mmap->button = 1;
      driver->endScene();
    }
  device->drop();
  end_co(cl);
  delete(mmap);
}

static void	my_connect(int port, char *ip)
{
  t_client		*cl;

  cl = (t_client *)malloc(sizeof(t_client *) + 100);
  cl->port = port;
  cl->ip = ip;
  client(cl);
  my_graph(cl);
  exit (0);
}

int	main(int ac, char **av)
{
  int	ipo;
  char	*name;
  int	port;
  int	ina;

  srand(time(NULL));
  ipo = ina = port = 0;
  name = (char *)"";
  if (ac == 1 || ac % 2 == 0 || ac > 5)
    print_usage();
  if (av[1] && av[2] && strcmp(av[1], "-p") == 0)
    {
      ipo = 1;
      port = atoi(av[2]);
    }
  else if (av[1] && av[2] && strcmp(av[1], "-h") == 0)
    {
      ina = 1;
      name = strdup(av[2]);
    }
  else
    print_usage();
  if (av[3] && av[4] && strcmp(av[3], "-p") == 0 && ipo == 0)
    port = atoi(av[4]);
  else if (av[3] && av[4] && strcmp(av[3], "-h") == 0 && ina == 0)
    name = strdup(av[4]);
  else if (ipo == 0)
    print_usage();
  else
    name = strdup("localhost");
  if (strcmp(name, "localhost") == 0)
    name = strdup("127.0.0.1");
  my_connect(port, name);
}
