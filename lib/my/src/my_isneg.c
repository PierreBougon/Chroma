/*
** my_isneg.c for my_isneg in /home/theis_p/git/Piscine_C_J03
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Wed Sep 30 09:59:46 2015 Paul THEIS
** Last update Thu Oct  1 17:08:24 2015 Paul THEIS
*/

#include "./my.h"

int	my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  else if (n >= 0)
    my_putchar('P');
  return (0);
}
