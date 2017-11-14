/*
** circular_buffer.c for PSU_2016_myirc
**
** Made by	Gauthier Harnisch
** Login	harnis_g
**
** Started on	Mon Jun 05 10:49:25 2017 Gauthier Harnisch
** Last update	Mon Jun 26 11:55:43 2017 Gauthier Harnisch
*/

#include "client.h"

t_buff	*new_buff(int nb_el)
{
  t_buff *ret;

  if (!(ret = (t_buff *)malloc(sizeof(t_buff))) ||
      !(ret->data = malloc(nb_el * sizeof(char))))
    error(84, "malloc failed");
  ret->max_el = nb_el;
  ret->nb_el = 0;
  ret->end = 0;
  ret->beg = 0;
  return (ret);
}

char	*buff_get(t_buff *buff)
{
  char	*ret;

  if (buff->nb_el == 0)
    return (NULL);
  if (!(ret = (char *)malloc(sizeof(char) * (buff->nb_el + 1))))
    error(84, "malloc failed");
  if (buff->end < buff->beg)
    memcpy(ret, (char *)buff->data + buff->end, buff->nb_el);
  else
    {
      memcpy(ret, (char *)buff->data + buff->end, buff->max_el - buff->end);
      memcpy(ret + buff->max_el - buff->end, buff->data, buff->beg);
    }
  ret[buff->nb_el] = 0;
  return (ret);
}

t_buff	*buff_move_end(t_buff *buff, int i)
{
  if (i > buff->nb_el)
    error(0, "underflow in ring buffer");
  buff->end = (i + buff->end) % buff->max_el;
  buff->nb_el = buff->nb_el - i;
  return (buff);
}

t_buff	*buff_empty(t_buff *buff)
{
  buff->end = buff->beg;
  buff->nb_el = 0;
  return (buff);
}

void	del_buff(t_buff *buff)
{
  free(buff->data);
  free(buff);
}
