/*
** my_strlen.c for my_strlen.c in /home/theis_p/git/Piscine_C_J04
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Thu Oct  1 09:22:46 2015 Paul THEIS
** Last update Thu Oct  1 12:07:09 2015 Paul THEIS
*/

#include "./my.h"

int	my_strlen(char *str)
{
  int	n;
  int	i;

  n = 0;
  i = 0;

  while (str[i])
    {
      n++;
      i++;
    }
  return (n);
}
