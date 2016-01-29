/*
** my_str_isnum.c for my_str_isnum in /home/theis_p/git/Piscine_C_J06
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Mon Oct  5 16:01:02 2015 Paul THEIS
** Last update Mon Oct 12 14:20:30 2015 Paul THEIS
*/

#include "./my.h"

int	my_str_isnum(char *str)
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
	  if (my_char_isnum(str[i]))
	    {
	    }
	  else
	    mark = 0;
	  i = i + 1;
	}
    }
  return (mark);
}
