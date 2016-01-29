/*
** check.c for printf in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 17:58:56 2015 theis_p
** Last update Sat Nov  7 17:58:58 2015 theis_p
*/

#include "../include/my_printf.h"

int		is_params_nbr(const char *str)
{
  unsigned int	i;

  i = 0;
  if (str[i] == CPUR)
    ++i;
  while (str[i] && my_char_isnum(str[i]))
    ++i;
  if (i > 0 && str[i] == '$' && str[i - 1] != CPUR)
    return (i);
  return (0);
}

unsigned int	check_last_char(const char *str, unsigned int i)
{
  if (str[i] == 'h' || str[i] == 'l' || str[i] == 'z' ||
      str[i] == 'j' || str[i] == 't')
    ++i;
  if (str[i] == 'h' || str[i] == 'l')
    ++i;
  if (i == 0 && str[1] == '$')
    return (0);
  if (str[i] == 'd' || str[i] == 's' || str[i] == 's' || str[i] == 'u' ||
      str[i] == 'x' || str[i] == 'X' || str[i] == 'o' || str[i] == 'p' ||
      str[i] == CPUR || str[i] == 'i' || str[i] == 'b' || str[i] == 'S' ||
      str[i] == 'n' || str[i] == 'c')
    return (i);
  return (0);
}

unsigned int	is_to_convert(const char *str)
{
  unsigned int	i;

  i = 0;
  if (str[i] == CPUR)
    ++i;
  if (is_params_nbr(str) > 0)
    i = is_params_nbr(str) + 1;
  while (str[i] == '+' || str[i] == ' ' || str[i] == '-' ||
	 str[i] == '#' || str[i] == '0')
    ++i;
  if (str[i] == '*')
    ++i;
  while (my_char_isnum(str[i]))
    ++i;
  if (str[i] == '.')
  {
    ++i;
    if (str[i] == '*')
      ++i;
    while (my_char_isnum(str[i]))
      ++i;
  }
  return (check_last_char(str, i));
}
