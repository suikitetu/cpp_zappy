/*
** Inventory.c for  in /home/blinea_s/rendu/tek2/PSU_2016_zappy
**
** Made by Sébastien Blineau
** Login   <blinea_s@epitech.net>
**
** Started on  Wed Jun 21 11:39:41 2017 Sébastien Blineau
** Last update	Wed Jun 28 15:41:48 2017 Gauthier Harnisch
*/

#include "zappy.h"

static int	get_size(int i)
{
  int	n;
  int	size;

  n = i;
  size = 0;
  while (n > 0)
    {
      n /= 10;
      size++;
    }
  return (size);
}

char	*itoa_zero()
{
  char	*nbr;

  if ((nbr = (char *)malloc(sizeof(char) * 2)) == NULL)
    error(84, "Malloc failed\n");
  nbr[0] = '0';
  nbr[1] = 0;
  return (nbr);
}

char	*itoa(int i)
{
  char	*nbr;
  int	x;
  int	y;
  int	power;
  int	n;

  if (i == 0)
    return (itoa_zero());
  if ((nbr = (char *)malloc(sizeof(char) * get_size(i) + 1)) == NULL)
    error(84, "Malloc failed\n");
  x = get_size(i);
  y = 0;
  while (y < x)
    {
      power = 1;
      n = x - y - 1;
      while (n--)
	power *= 10;
      nbr[y] = i / power + '0';
      i %= power;
      y++;
    }
  nbr[y] = '\0';
  return (nbr);
}

char	**inventory_to_chararray(int *inventory)
{
  char	**new_inventory;
  int	i;

  i = 0;
  if (!(new_inventory = (char **)malloc(sizeof(char *) * 7)))
    error(84, "malloc failed");
  while (i < 7)
    {
      if ((new_inventory[i] = malloc(255)) == NULL)
	error(84, "Malloc failed");
      sprintf(new_inventory[i], "%d", inventory[i]);
      i++;
    }
  return (new_inventory);
}

void	inventory(t_serv *serv, int i, char **tab)
{
  char	**invent_tab;
  int	j;

  (void)tab;
  invent_tab = inventory_to_chararray(serv->cli[i]->inventory);
  send_cli(serv->cli[i], (char *)"[food ");
  send_cli(serv->cli[i], invent_tab[6]);
  send_cli(serv->cli[i], (char *)", linemate ");
  send_cli(serv->cli[i], invent_tab[0]);
  send_cli(serv->cli[i], (char *)", deraumere ");
  send_cli(serv->cli[i], invent_tab[1]);
  send_cli(serv->cli[i], (char *)", sibur ");
  send_cli(serv->cli[i], invent_tab[2]);
  send_cli(serv->cli[i], (char *)", mendiane ");
  send_cli(serv->cli[i], invent_tab[3]);
  send_cli(serv->cli[i], (char *)", phiras ");
  send_cli(serv->cli[i], invent_tab[4]);
  send_cli(serv->cli[i], (char *)", thystame ");
  send_cli(serv->cli[i], invent_tab[5]);
  send_cli(serv->cli[i], (char *)"]\n");
  j = -1;
  while (++j < 7)
    free(invent_tab[j]);
  free(invent_tab);
}
