/*
** swrite.c for printf in /home/theis_p/my_printf
**
** Made by Paul THEIS
** Login   <theis.p@epitech.net>
**
** Started on  Sat Nov 14 15:56:24 2015 Paul THEIS
** Last update Sat Nov 14 15:57:39 2015 Paul THEIS
*/

#include "../include/my_printf.h"

unsigned int	save_chars(t_tmp_arg *tmp, unsigned int schars)
{
  *(tmp->schars) = schars;
  return (0);
}
