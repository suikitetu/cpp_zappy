/*
** death.c for PSU_2016_zappy
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Thu Jun 29 15:03:39 2017 Gauthier Harnisch
** Last update	Sun Jul 02 16:40:41 2017 Gauthier Harnisch
*/

#include "zappy.h"

void	pdi(t_serv *serv, int i)
{
  char	*str;

  if (!(str = (char *)malloc(MAXLINE)))
    error(84, "malloc failed");
  sprintf(str, "pdi %d\n", serv->cli[i]->id);
  send_graph(serv, str);
  free(str);
}

void	death(t_serv *serv, int i)
{
  serv->cli[i]->life = serv->cli[i]->life - 1;
  if (serv->cli[i]->life <= 0)
    {
      if (serv->cli[i]->inventory[6] <= 0)
        remove_client(serv, i);
      else
	{
	  serv->cli[i]->inventory[6] = serv->cli[i]->inventory[6] - 1;
	  serv->cli[i]->life = 126;
	}
    }
}

void	death_egg(t_serv *serv, int i)
{
  char *str;

  serv->egg[i]->life -= 1;
  if (serv->egg[i]->life <= 0)
    {
      if (serv->egg[i]->food == 0)
        {
          if (!(str = (char *)malloc(MAXLINE)))
            error(84, "malloc failed");
          sprintf(str, "edi %d\n", serv->egg[i]->id);
          remove_egg(serv, i);
          send_graph(serv, str);
          free(str);
        }
      else
        {
          serv->egg[i]->food -= 1;
          serv->egg[i]->life = 126;
        }
    }
}
