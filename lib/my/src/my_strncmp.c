/*
** my_strncmp.c for my_strncmp in /home/theis_p/git/Piscine_C_J06
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Mon Oct  5 15:14:11 2015 Paul THEIS
** Last update Mon Oct 12 14:22:28 2015 Paul THEIS
*/

#include "./my.h"

int     my_strncmp(char *s1, char *s2, int n)
{
  int   x;
  int   y;
  int   z;

  x = 0;
  y = 0;
  z = 1;
  if (n == 0)
    return (0);
  while (s1[x] && s2[y] && s1[x] == s2[y] && z < n)
    {
      x++;
      y++;
      z++;
    }
  return (s1[x] - s2[y]);
}
