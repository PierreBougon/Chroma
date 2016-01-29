/*
** my_strdup.c for strdup in
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Jan  8 13:35:43 2016 Paul THEIS
** Last update Fri Jan  8 13:56:32 2016 Paul THEIS
*/

#include <stdlib.h>
#include "./my.h"

char		*my_strdup(char *str)
{
  char		*ret;
  int		i;

  i = 0;
  if ((ret = malloc(my_strlen(str) * sizeof(char) + 1)) == NULL)
    return (NULL);
  while (str[i])
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}
