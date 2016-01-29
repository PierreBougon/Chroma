/*
** my_str_isalpha.c for my_str_isalpha in /home/theis_p/git/Piscine_C_J06
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Mon Oct  5 15:58:26 2015 Paul THEIS
** Last update Tue Oct  6 15:23:35 2015 Paul THEIS
*/

#include "./my.h"

int	my_str_isalpha(char *str)
{
  int	i;
  int	mark;

  i = 0;
  mark = 1;
  if (*str == 0)
    return (1);
  else
    {
      while (str[i] != '\0')
	{
	  if (str[i] >= 'A' && str[i] <= 'Z')
	    {
	    }
	  else if (str[i] >= 'a' && str[i] <= 'z')
	    {
	    }
	  else
	    mark = 0;
	  i = i + 1;
	}
      return (mark);
    }
}
