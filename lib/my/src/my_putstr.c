/*
** my_putstr.c for my_putstr in /home/theis_p/git/Piscine_C_J04
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Thu Oct  1 09:19:34 2015 Paul THEIS
** Last update Thu Oct  1 17:49:18 2015 Paul THEIS
*/

#include "./my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
