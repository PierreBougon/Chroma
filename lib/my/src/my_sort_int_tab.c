/*
** my_sort_int_tab.c for my_sort_int_tab in /home/theis_p/git/Piscine_C_J04
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Thu Oct  1 13:56:21 2015 Paul THEIS
** Last update Thu Oct  1 16:37:27 2015 Paul THEIS
*/

#include "./my.h"

void    my_sort_int_tab(int *tab, int size)
{
  int	a;
  int	b;
  int	tmp;

  a = 0;
  while (a < size)
    {
      b = a + 1;
      while (b < size)
        {
          if (tab[a] > tab[b])
            {
              tmp = tab[a];
              tab[a] = tab[b];
              tab[b] = tmp;
            }
          b++;
        }
      a++;
    }
}
