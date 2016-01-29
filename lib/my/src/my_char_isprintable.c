/*
** my_char_isprintable.c for my_char_isprintable in /home/theis_p/my_printf/lib/my/src
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov  6 09:46:26 2015 theis_p
** Last update Fri Nov  6 09:48:44 2015 theis_p
*/

#include "./my.h"

int		my_char_isprintable(char c)
{
  if (c > 32 && c < 127)
    return (1);
  return (0);
}
