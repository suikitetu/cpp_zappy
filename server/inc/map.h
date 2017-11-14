/*
** map.h for PSU_2016_zappy
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Wed Jun 28 15:00:14 2017 Gauthier Harnisch
** Last update	Sat Jul 01 12:08:56 2017 Gauthier Harnisch
*/

# ifndef	_MAP_H
# define _MAP_H_

# define	RAND_L 5
# define	RAND_D 5
# define	RAND_S 5
# define	RAND_M 5
# define	RAND_P 5
# define	RAND_T 5
# define	RAND_F 10

# define	RAND_DENSE 4

enum RESSOURCE
  {
    LINEMMATE = 0,
    DERAUMERE = 1,
    SIBUR = 2,
    MENDIANE = 3,
    PHIRAS = 4,
    THYSTAME = 5,
    FOOD = 6
  };

typedef struct	s_map
{
  int		x;
  int		y;
  int		ressources[7];
}t_map;

t_map	**map_generate(int x, int y);
void    map_refresh(t_map **map, int to_add, int sizex, int sizey);
void	del_map(t_map **map, int x);

#endif
