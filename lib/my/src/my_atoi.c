/*
** my_atoi.c for my_atoi in /home/theis_p/my_printf/lib/my/src
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov  6 09:45:05 2015 theis_p
** Last update Sat Nov  7 16:30:08 2015 theis_p
*/

#include "./my.h"

int	my_atoi(const char *str)
{
  int	i;
  int	number;

  i = 0;
  number = 0;
  while (my_char_isnum(str[i]))
  {
    number *= 10;
    number += ((int)str[i++] - '0');
  }
  return (number);
}
