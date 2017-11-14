//
// my_str_to_wordtab.cpp for my_str_to_wordtab in /home/mag_d/rendu/PSU_2016_zappy/client/src
// 
// Made by david mag
// Login   <mag_d@epitech.net>
// 
// Started on  Wed Jun 28 14:58:41 2017 david mag
// Last update Wed Jun 28 16:02:04 2017 david mag
//

#include "client.h"

std::vector<std::string>	wordtab(char *str, char c)
{
  int				i;
  std::vector<std::string>	tab;
  std::string			word;
  
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != c)
	word.push_back(str[i]);
      else
	{
	  tab.push_back(word);
	  word.clear();
	}
      i++;
    }
  tab.push_back(word);
  word.clear();
  return (tab);
}
