/*
** my_strcat.c for my_strcat in /home/theis_p/git/Piscine_C_J07
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Tue Oct  6 16:01:04 2015 Paul THEIS
** Last update Mon Oct 12 14:23:10 2015 Paul THEIS
*/

#include "./my.h"

char *my_strcat(char *dest, char *src)
{
  char	*tmp;

  tmp = dest;
  while (*dest)
    {
      dest++;
    }
  while (*src)
    {
      *dest = *src;
      dest++;
      src++;
    }
  return (tmp);
}
