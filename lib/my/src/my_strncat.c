/*
** my_strncat.c for my_strncat.c in /home/theis_p/git/Piscine_C_J07
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Tue Oct  6 16:20:29 2015 Paul THEIS
** Last update Tue Oct  6 23:53:33 2015 Paul THEIS
*/

#include "./my.h"

char *my_strncat(char *dest, char *src, int nb)
{
  char  *tmp;

  tmp = dest;
  while (*dest)
    {
      dest++;
    }
  while (*src && nb != 0)
    {
      *dest = *src;
      dest++;
      src++;
      nb--;
    }
  dest++;
  *dest = '\0';
  return (tmp);
}
