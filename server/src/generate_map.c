/*
** cleanup.c for PSU_2016_myftp
**
** Made by	Gauthier Harnisch
** Login	harins_g
**
** Started on	Fri May 12 10:47:48 2017 Gauthier Harnisch
** Last update	Fri Jun 30 11:52:42 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	del_map(t_map **map, int x)
{
  int	ix;

  ix = -1;
  while (++ix < x)
    free(map[ix]);
  free(map);
}

t_map	**map_gen_res(t_map **map, int x, int y)
{
  int	i;
  int	res;

  i = -1;
  srand(time(NULL));
  while (++i < (x * y * RAND_DENSE))
    {
      res = rand();
      res %= (RAND_L + RAND_D + RAND_S + RAND_M + RAND_P + RAND_T + RAND_F);
      res = res - RAND_L + (res <= 0) * (1 << 31);
      map[rand() % x][rand() % y].ressources[0] += (res <= 0);
      res = res - RAND_D + (res <= 0) * (1 << 31);
      map[rand() % x][rand() % y].ressources[1] += (res <= 0);
      res = res - RAND_S + (res <= 0) * (1 << 31);
      map[rand() % x][rand() % y].ressources[2] += (res <= 0);
      res = res - RAND_M + (res <= 0) * (1 << 31);
      map[rand() % x][rand() % y].ressources[3] += (res <= 0);
      res = res - RAND_P + (res <= 0) * (1 << 31);
      map[rand() % x][rand() % y].ressources[4] += (res <= 0);
      res = res - RAND_T + (res <= 0) * (1 << 31);
      map[rand() % x][rand() % y].ressources[5] += (res <= 0);
      res = res - RAND_F + (res <= 0) * (1 << 31);
      map[rand() % x][rand() % y].ressources[6] += (res <= 0);
    }
  return (map);
}

t_map	**map_generate(int x, int y)
{
  t_map	**map;
  int	ix;
  int	iy;

  ix = -1;
  if (!(map = (t_map **)malloc(sizeof(t_map *) * x)))
    error(84, "map_generate0:malloc failed");
  while (++ix < x && (iy = -1))
    {
      if (!(map[ix] = (t_map *)malloc(sizeof(t_map) * y)))
        error(84, "map_generate1:malloc failed");
      while (++iy < y)
        {
          map[ix][iy].x = ix;
          map[ix][iy].y = iy;
          map[ix][iy].ressources[0] = 0;
          map[ix][iy].ressources[1] = 0;
          map[ix][iy].ressources[2] = 0;
          map[ix][iy].ressources[3] = 0;
          map[ix][iy].ressources[4] = 0;
          map[ix][iy].ressources[5] = 0;
          map[ix][iy].ressources[6] = 0;
        }
    }
  return (map_gen_res(map, x, y));
}

void	map_refresh(t_map **map, int to_add, int sizex, int sizey)
{
  map[rand() % sizex][rand() % sizey].ressources[to_add] += 1;
}
