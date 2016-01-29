/*
** my_bzero.c for bzero in /home/theis_p/lib/my/src
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Wed Dec 30 20:25:21 2015 Paul THEIS
** Last update Wed Dec 30 20:25:50 2015 Paul THEIS
*/

#include "./my.h"

void	my_bzero(void *s, size_t n)
{
  s = my_memset(s, '\0', n);
}
