//
// player.hpp for player in /home/mag_d/rendu/PSU_2016_zappy/client_src
//
// Made by david mag
// Login   <mag_d@epitech.net>
//
// Started on  Mon Jun 19 16:40:57 2017 david mag
// Last update Sun Jul  2 15:52:47 2017 david mag
//

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "client.h"

#define LAST_FOOD 50
#define LAST_MINERAL 60

namespace				player
{
  static int const			prerequiIncantation[7][7] = {{1, 0, 0, 0, 0, 0, 1},
 								     {1, 1, 1, 0, 0, 0, 2},
								     {2, 1, 1, 1, 0, 0, 2},
								     {1, 1, 2, 0, 1, 0, 4},
								     {1, 2, 1, 3, 0, 0, 4},
								     {1, 2, 3, 0, 1, 0, 6},
								     {2, 2, 2, 2, 2, 1, 6}};
  
  enum					mineralList
    {
      LINEMATE = 0,
      DERAUMERE,
      SIBUR,
      MENDIANE,
      PHIRAS,
      THYSTAME
    };

  class					stat
  {
  protected:
    int					hunger;
    int					food;
    int					elevation;
    std::vector<int>			mineral;
    
  public:
    stat();
    stat(stat const & stat);
    ~stat();

    int					getMineral(mineralList element) const;
    void				setMineral(mineralList element, int nbr);

    int					getHunger() const;
    void				setHunger(int hunger);
     
    int					getElevation() const;
    void				setElevation(int elevation);

    int					getFood() const;
    void				setFood(int food);
    
    stat&				operator=(stat const & stat);
  };

  typedef struct			s_tile
  {
    int					food;
    std::vector<int>			mineral;
    int					lastSeen;
    int					player;
  }					t_tile;

  enum					oriantation
  {
    NORD,
    EST,
    SUD,
    OUEST
  };
  
  class					command : public stat
  {
  protected:
    std::vector<std::vector<t_tile> >	mapVision;
    int					mapSizeX;
    int					mapSizeY;
    int					posX;
    int					posY;
    int					oriantation;
    int					f;
    
  public:
    command(int x, int y);
    command(command const & command);
    ~command();

    std::queue<std::string>		taskList;
    char				*playerReceive();

    int					*findFood() const;
    int					*findMineral(mineralList element) const;
    player::t_tile const		getTile(int x, int y) const;
    
    int					getOriantation();

    void				setMapSizeX(int mapSizeX);
    int					getMapSizeX() const;
    
    void				setMapSizeY(int mapSizeY);
    int					getMapSizeY() const;
    
    void				setPosX(int posX);
    int					getPosX() const;

    void				setPosY(int posY);
    int					getPosY() const;

    void				forward();
    void				setOriantation(player::oriantation end);
    void				turnRight();
    void				turnLeft();

    void				setTile(std::string str, int x, int y);
    void				lookNord(std::vector<std::string> tab);
    void				lookEst(std::vector<std::string> tab);
    void				lookSud(std::vector<std::string> tab);
    void				lookOuest(std::vector<std::string> tab);
    void				look();

    void				inventory();
    void				broadcastText(std::string message);
    void				connectNbr();
    void				forkPlayer();
    bool				ejectPlayer();
    void				death();

    void				clean();
    void				takeObject(std::string object, mineralList element, bool food);
    void				place();
    void				setObject(std::string object, mineralList element, bool food);

    bool				incantationCall();
    command&				operator=(command const & command);
  };

  class					script : public command
  {
  public:
    script(int x, int y);
    script(script const & script);
    ~script();
    void				takeParasite();
    void				setLevelObjects();
    void				setIncantation();
    void				searchFood();
    void				searchMineral(player::mineralList element);
    void				search();
    void				myGoTo(int x, int y);
    void				doTask();
    void				gatherMineral();
    void				incantation();
    const std::vector<std::string>	explode(const std::string& s, const char& c);
    void				find();
  };
};

#endif /* ! PLAYER_HPP_ */
