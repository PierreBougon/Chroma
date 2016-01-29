/*
** my_is_prime.c for my_is_prime in /home/theis_p/git/Piscine_C_J05
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Oct  2 10:54:13 2015 Paul THEIS
** Last update Fri Oct  2 10:56:50 2015 Paul THEIS
*/

#include "./my.h"

int     my_is_prime(int nb)
{
  int   i;
  int   mark;

  i = 2;
  if (nb == 2)
    return (1);
  else if (nb > 2)
    {
      mark = 1;
      while (i < nb)
        {
          if (nb % i == 0)
            mark = 0;
          i = i + 1;
        }
      return (mark);
    }
  else
    return (0);
}
