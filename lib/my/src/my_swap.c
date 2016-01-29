/*
** my_swap.c for my_swap in /home/theis_p/git/Piscine_C_J04
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Thu Oct  1 09:17:50 2015 Paul THEIS
** Last update Thu Oct  1 12:07:53 2015 Paul THEIS
*/

#include "./my.h"

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
