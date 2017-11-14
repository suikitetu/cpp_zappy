//
// Event.hpp for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy/client_graph/inc
// 
// Made by Sébastien Blineau
// Login   <blinea_s@epitech.net>
// 
// Started on  Thu Jun  8 10:28:08 2017 Sébastien Blineau
// Last update Sun Jul  2 19:58:41 2017 DOYON Etienne
//

#ifndef EVENT_HPP_
# define EVENT_HPP_

#ifdef _MSC_VER
#pragma comment(lib, "lib/Irrlicht.lib")
#endif

#include <../lib/inc/irrlicht.h>
#include <../lib/inc/IEventReceiver.h>

class	MyEventReceiver : public irr::IEventReceiver
{
private:
  // We use this array to store the current state of each key
  bool	KeyIsDown[irr::KEY_KEY_CODES_COUNT];
  int	mouseX;
  int	mouseY;
public:

  int   selectedX;
  int   selectedY;
  MyEventReceiver()
  {
    this->mouseX = 0;
    this->mouseY = 0;
    this->selectedX = this->selectedY = -1;
    for (irr::u32 i=0; i<irr::KEY_KEY_CODES_COUNT; ++i)
      KeyIsDown[i] = false;
  }

  // This is the one method that we have to implement
  virtual bool OnEvent(const irr::SEvent& event)
  {
    int	XX;
    int	YY;
    int	i;
    
    // Remember whether each key is down or up
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
      KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
      {
	switch(event.MouseInput.Event)
	  {
	  case irr::EMIE_MOUSE_MOVED:
	    this->mouseX = event.MouseInput.X;
	    this->mouseY = event.MouseInput.Y;
	    break;
	  case irr::EMIE_LMOUSE_PRESSED_DOWN:
	    this->selectedX = mouseX;
	    this->selectedY = mouseY;
	    break;
	  }
      }

    return false;
  }

  // This is used to check whether a key is being held down
  virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const
  {
    return KeyIsDown[keyCode];
  }

  int	getmouseX() { return (this->mouseX); }
  int   getmouseY() { return (this->mouseY); }
  
};

#endif
