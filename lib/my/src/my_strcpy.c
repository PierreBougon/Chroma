/*
** my_strcpy.c for my_strcpy in /home/theis_p/git/Piscine_C_J06
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Mon Oct  5 09:42:46 2015 Paul THEIS
** Last update Mon Oct 12 14:21:10 2015 Paul THEIS
*/

#include "./my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
