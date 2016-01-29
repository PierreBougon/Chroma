/*
** my_strcmp.c for my_strcmp in /home/theis_p/git/Piscine_C_J06
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Mon Oct  5 14:30:26 2015 Paul THEIS
** Last update Mon Oct  5 14:31:23 2015 Paul THEIS
*/

#include "./my.h"

int     my_strcmp(char *s1, char *s2)
{
  int   x;
  int   y;
  int   num;

  x = 0;
  y = 0;
  if (s1 == 0 || s2 == 0)
    return (0);
  while (s1[y] != '\0' && s2[x] != '\0' && s1[y] == s2[x])
    {
      x++;
      y++;
    }
  num = s1[x] - s2[y];
  return (num);
}
