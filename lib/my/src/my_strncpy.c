/*
** my_strncpy.c for my_strncpy in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 18:01:07 2015 theis_p
** Last update Sat Nov  7 18:01:09 2015 theis_p
*/

#include "./my.h"

char    *my_strncpy(char *dest, char *src, int n)
{
  int	count;

  count = 0;
  while (src[count] != '\0' && count < n)
    {
      dest[count] = src[count];
      count++;
    }
  dest[count] = '\0';
  return (dest);
}
