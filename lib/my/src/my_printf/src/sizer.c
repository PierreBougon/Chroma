/*
** sizer.c for printf in /home/theis_p/my_printf
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov 14 16:03:54 2015 Paul THEIS
** Last update Sat Nov 14 16:03:57 2015 Paul THEIS
*/

#include "../include/my_printf.h"

unsigned int	sizer_int(long nb)
{
  unsigned int	i;

  i = 1;
  if (nb < 0)
  {
    i = 2;
    nb = -nb;
  }
  while (nb / 10 > 0)
  {
    ++i;
    nb = nb / 10;
  }
  return (i);
}

unsigned int	sizer_uint(unsigned long nb)
{
  unsigned int	i;

  i = 1;
  while (nb / 10 > 0)
  {
    ++i;
    nb = nb / 10;
  }
  return (i);
}

unsigned int	sizer_octal(unsigned long nb)
{
  unsigned int	i;

  i = 1;
  while (nb / 8 > 0)
  {
    nb = nb / 8;
    ++i;
  }
  return (i);
}

unsigned int	sizer_hexa(unsigned long nb)
{
  unsigned int	i;

  i = 1;
  while (nb / 16 > 0)
  {
    nb = nb / 16;
    ++i;
  }
  return (i);
}

unsigned int	sizer_binary(unsigned long nb)
{
  unsigned int	i;

  i = 1;
  while (nb / 2 > 0)
  {
    nb = nb / 2;
    ++i;
  }
  return (i);
}
