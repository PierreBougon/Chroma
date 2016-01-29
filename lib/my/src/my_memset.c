/*
** my_memset.c for memset in /home/theis_p/lib/my/src
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Wed Dec 30 20:22:35 2015 Paul THEIS
** Last update Wed Dec 30 20:26:03 2015 Paul THEIS
*/

#include "./my.h"

void		*my_memset(void *b, int c, size_t len)
{
  size_t	counter;
  char		*str;

  str = (char *)b;
  if (!str)
    return (NULL);
  if (len == 0)
    return (str);
  counter = 0;
  while (counter < len)
    {
      str[counter] = (char)c;
      counter++;
    }
  return (b);
}
