/*
** my_putstr_err.c for my_putstr_err in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 17:13:37 2015 theis_p
** Last update Sat Nov  7 17:13:39 2015 theis_p
*/

#include "./my.h"

int		my_putstr_err(char *str)
{
  write(2, str, my_strlen(str));
  return (0);
}
