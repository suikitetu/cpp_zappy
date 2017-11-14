/*
** circular_buffer1.c for PSU_2016_myirc
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Tue Jun 06 12:11:09 2017 Gauthier Harnisch
** Last update	Sun Jul 02 11:04:08 2017 Gauthier Harnisch
*/

#include "client.h"

t_buff	*buff_push_front(t_buff *buff, char *data, int size)
{
  int	i;

  if (buff->nb_el + size > buff->max_el)
    {
      buff_empty(buff);
      error(0, "ring buffer overflow:purged");
      return (NULL);
    }
  buff->nb_el += size;
  i = 0;
  while (i < size)
    {
      ((char *)buff->data)[buff->beg % buff->max_el] = data[i++];
      buff->beg = (buff->beg + 1) % buff->max_el;
    }
  return (buff);
}

char	*buff_pop_front(t_buff *buff, int size)
{
  char	*res;
  int	i;

  if (buff->nb_el - size < 0)
    error(84, "ring buffer underflow");
  if (!(res = (char *)malloc(sizeof(char) * size + 1)))
    error(84, "malloc failed");
  i = size;
  while (i > 0)
    {
      buff->nb_el--;
      buff->beg = (buff->beg - 1) % buff->max_el;
      res[--i] = (((char *)buff->data)[buff->beg % buff->max_el]);
    }
  return (res);
}

t_buff	*buff_push_back(t_buff *buff, char *data, int size)
{
  int	i;

  if (buff->nb_el + size > buff->max_el)
    {
      buff_empty(buff);
      error(0, "ring buffer overflow:purged");
      return (NULL);
    }
  buff->nb_el += size;
  i = size;
  while (i > 0)
    {
      buff->end = (buff->end - 1 + buff->max_el) % buff->max_el;
      ((char *)buff->data)[buff->end % buff->max_el] = data[--i];
    }
  return (buff);
}

char	*buff_pop_back(t_buff *buff, int size)
{
  char	*res;
  int	i;

  if (buff->nb_el - size < 0)
    error(84, "ring buffer underflow");
  if (!(res = (char *)malloc(sizeof(char) * size + 1)))
    error(84, "malloc failed");
  i = 0;
  buff->nb_el -= size;
  while (i < size)
    {
      res[i++] = (((char *)buff->data)[buff->end % buff->max_el]);
      buff->end = (buff->end + 1 + buff->max_el) % buff->max_el;
    }
  res[i] = 0;
  return (res);
}

char	*buff_pop_line(t_buff *buff)
{
  int	i;
  char	*res;

  i = 0;
  while (i < buff->nb_el)
    {
      if (((char *)buff->data)[(buff->end + i) % buff->max_el] == '\n')
        {
          res = buff_pop_back(buff, i + 1);
          res[i] = 0;
          return (res);
        }
      i++;
    }
  return (NULL);
}
