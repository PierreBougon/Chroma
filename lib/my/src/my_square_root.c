/*
** my_square_root.c for my_square_root in /home/theis_p/git/Piscine_C_J05
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Oct  2 11:01:13 2015 Paul THEIS
** Last update Fri Oct  2 11:09:59 2015 Paul THEIS
*/

#include "./my.h"

int     my_square_root(int nb)
{
  int   x;
  int   mark;

  x = 0;
  mark = 0;
  while ((x * x) <= nb)
    {
      if (x * x == nb)
        mark = x;
      x++;
    }
  return (mark);
}
