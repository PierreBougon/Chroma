/*
** my_put_nbr.c for my_put_nbr in /home/theis_p/git/Piscine_C_J03
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Wed Sep 30 14:07:08 2015 Paul THEIS
** Last update Thu Oct  1 17:33:47 2015 Paul THEIS
*/

#include "./my.h"

int	isneg2(int *nb)
{
  if (*nb < 0)
  {
    my_putchar('-');
    *nb = -(*nb);
  }
  return (0);
}

int	my_putnbr(int nb)
{
  int	div_nbr;
  int	result;

  div_nbr = 1;
  result = 0;
  if (nb == -2147483648)
    return (-2147483648);

  isneg2(&nb);

  while ((nb / div_nbr) >= 10)
    div_nbr *= 10;
  while (div_nbr > 0)
    {
      result = (nb / div_nbr) % 10;
      my_putchar(48 + result);
      div_nbr /= 10;
    }
  return (0);
}
