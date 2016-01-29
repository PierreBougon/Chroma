/*
** my_putchar.c for printf in /home/theis_p/my_printf
**
** Made by Paul THEIS
** Login   <theis.p@epitech.net>
**
** Started on  Sat Nov 14 15:59:40 2015 Paul THEIS
** Last update Sat Nov 14 15:59:42 2015 Paul THEIS
*/

#include "./my.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
