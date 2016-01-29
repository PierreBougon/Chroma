/*
** my_strlcat.c for my_strlcat in /home/theis_p/git/Piscine_C_J07
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Tue Oct  6 19:25:57 2015 Paul THEIS
** Last update Mon Oct 12 14:23:41 2015 Paul THEIS
*/

#include "./my.h"

int	my_strlcat(char *dest, char *src, int size)
{
  int	n;
  int	l1;
  int	l2;

  l1 = my_strlen(dest);
  l2 = my_strlen(src);
  if (l1 > size)
    return (size + l2);
  n = 0;
  while (n + l1 < size - 1&& src[n])
    {
      dest[l1 + n] = src[n];
      n = n + 1;
    }
    dest[l1 + n] = '\0';
    return (l1 + l2);
}
