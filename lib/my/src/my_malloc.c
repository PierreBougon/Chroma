/*
** my_malloc.c for malloc in /home/theis_p/lib/my/src
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Wed Dec 30 20:20:18 2015 Paul THEIS
** Last update Fri Jan  8 13:55:20 2016 Paul THEIS
*/

#include "./my.h"

void		*my_malloc(size_t size)
{
  void		*mem;

  if (((mem = (void*)malloc(size))) != NULL && size)
    {
      my_bzero(mem, size);
      return (mem);
    }
  return (NULL);
}
