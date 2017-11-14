/*
** strupcase.c for  in /home/tachet_b/Epitech-projects/PSU_reseaux/PSU_2016_zappy/server/src
** 
** Made by Benoit Tachet
** Login   <tachet_b@epitech.net>
** 
** Started on  Sun Jul  2 15:00:37 2017 Benoit Tachet
** Last update Sun Jul  2 15:37:16 2017 Benoit Tachet
*/

#include "zappy.h"

char	*strupcase(char *str)
{
  int	i;
  char	*str_re;

  if ((str_re = malloc(strlen(str) + 1)) == NULL)
    error(84, "malloc failed");
  i = -1;
  while (str[++i])
    if (str[i] >= 'a' && str[i] <= 'z')
      {
	str_re[i] = str[i] - 'a' + 'A';
      }
    else
      str_re[i] = str[i];
  str_re[i] = '\0';
  return (str_re);
}
