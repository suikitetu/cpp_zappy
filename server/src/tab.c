/*
** str_tab.c for eval in /home/harnis_g/rendu/my_evalxpr
**
** Made by gauthier harnisch
** Login   <harnis_g@epitech.net>
**
** Started on  Fri Oct 14 12:15:04 2016 gauthier harnisch
** Last update	Mon May 29 17:09:39 2017 Gauthier Harnisch
*/

#include "zappy.h"

int	gc(char a, char *test)
{
  int   i;

  i = 0;
  while (test[i])
    if (test[i++] == a)
      return (i);
  if (a == 0)
    return (i);
  return (-1);
}

int	check_str(char *str, char *test)
{
  int	i;

  i = -1;
  while (str[++i])
    if (gc(str[i], test) == -1)
      return (1);
  return (0);
}

int	sep(char *str, int i, int p)
{
  if (!p && gc(str[i], (char *)SEP) != -1)
    return (1);
  return (0);
}

char	**str_tab2(char *str, char **res)
{
  int	k;
  int	l;
  int	i;
  int	p;

  p = (k = (i = (l = 0)));
  while (str[++i])
    {
      if (str[i] == '\"')
	p = !p;
      if (sep(str, i, p))
	{
	  if (!(res[k++] = extract(str, l, i - 1)))
	    {
	      return (NULL);
	    }
	  l = i;
	}
    }
  if (!(res[k++] = extract(str, l, i)))
    {
      return (NULL);
    }
  res[k] = NULL;
  return (res);
}

char	**str_tab(char *str)
{
  char	**res;
  int	k;
  int	i;
  int	p;

  i = 0;
  k = 1;
  p = 0;
  while (str[++i])
    {
      if (str[i] == '\"')
	p = !p;
      k = k + sep(str, i, p);
    }
  if (!(res = (char **)malloc(sizeof(char *) * (k + 2))))
    error(84, "malloc error in str_tab");
  res[k] = NULL;
  res[k + 1] = NULL;
  res = str_tab2(str, res);
  return (res);
}
