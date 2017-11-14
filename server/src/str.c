/*
** str.c for PSU_2016_myftp
**
** Made by	Gauthier Harnisch
** Login	harins_g
**
** Started on	Mon May 15 12:08:50 2017 Gauthier Harnisch
** Last update	Tue Jun 20 14:50:57 2017 Gauthier Harnisch
*/

#include "zappy.h"

int	match(const char *s1, const char *s2)
{
  if ((!*s1 && !*s2) || (*s2 == '*' && !*(s2 + 1)))
    return (1);
  else if (!*s1 || !*s2 || (*s2 != '*' && (*s1 != *s2)))
    return (0);
  if (*s2 == '*' && *(s2 + 1) == '*')
    return (match(s1, s2 + 1));
  if (*s1 == *s2)
    return (match(s1 + 1, s2 + 1));
  else if (*s2 == '*' && *s1 == *(s2 + 1))
    if (match(s1 + 1, s2 + 2))
      return (1);
  if (*s2 == '*')
    return (match(s1 + 1, s2));
  return (0);
}

int	tc(char a, const char *test)
{
  int   i;

  i = 0;
  while (test[i])
    if (test[i++] == a)
      return (i);
  return (0);
}

char	*clean_str(const char *i, const char *allow)
{
  int   k;
  int   s;
  char  *o;

  if ((k = -1) && !(o = (char *)malloc(sizeof(char) * strlen(i) + 2)))
    error(84, "malloc failed in clean_str");
  while (++k < (int)(strlen(i) + 2) && !(s = 0))
    o[k] = 0;
  k = 0;
  while (tc(i[s] , " \t"))
    s++;
  while (i[s])
    if (tc(i[s] , allow) && !(tc(i[s] , " \t")
    && (k <= 0 || tc(o[k - 1] , " \t"))))
      if (i[s++] == '\t')
        o[k++] = ' ';
      else
        o[k++] = i[s - 1];
    else
      s++;
  if (k > 0 && o[k - 1] == ' ')
    k--;
  o[k] = 0;
  return (o);
}

char	*extract(const char *line, int d, int f)
{
  int   i;
  char *res;

  if (!(res = (char *)malloc(sizeof(char) * (f - d + 2))))
    error(84, "malloc failed in extract");
  i = -1;
  while (line[d + ++i] != 0 && d + i <= f)
    res[i] = line[d + i];
  res[i] = 0;
  return (res);
}

char	*combine(const char *str, const char *add)
{
  int   i;
  int   k;
  char  *res;

  i = -1;
  if (!(res = (char *)malloc(strlen(str) + strlen(add) + 1)))
    error(84, "malloc failed in combine");
  res[strlen(str) + strlen(add)] = 0;
  while (str[++i])
    res[i] = str[i];
  k = -1;
  while (add[++k])
    res[i + k] = add[k];
  return (res);
}
