/*
** my_power_rec.c for my_power_rec in /home/theis_p/git/Piscine_C_J05
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Oct  2 10:27:11 2015 Paul THEIS
** Last update Fri Oct  2 12:32:16 2015 Paul THEIS
*/

#include "./my.h"

int	my_power_rec(int nb, int power)
{
  if (power == 1)
    return (nb);
  if (power == 0)
    return (0);
  if (power < 0)
    return (1);
  return (nb * my_power_rec(nb, (power - 1)));
}
