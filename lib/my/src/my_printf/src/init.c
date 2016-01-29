/*
** init.c for printf in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 15:53:56 2015 theis_p
** Last update Sat Nov  7 16:50:06 2015 theis_p
*/

#include "../include/my_printf.h"

void	init_params(t_params *params)
{
  params->is_other = 0;
  params->less = 0;
  params->plus = 0;
  params->space = 0;
  params->hash = 0;
  params->zero = 0;
  params->width = 0;
  params->is_size = 0;
  params->is_precision = 0;
  params->precision = 0;
  params->is_prec = 0;
  params->len = 0;
}

int	init_flags(t_params *params, const char *str, unsigned int i)
{
  while (str[i] == '+' || str[i] == ' ' || str[i] == '-' ||
	 str[i] == '#' || str[i] == '0')
  {
    (str[i] == '-') ? (params->less = 1) : 0;
    (str[i] == '+') ? (params->plus = 1) : 0;
    (str[i] == ' ') ? (params->space = 1) : 0;
    (str[i] == '#') ? (params->hash = 1) : 0;
    (str[i] == '0') ? (params->zero = 1) : 0;
    ++i;
  }
  if (my_char_isnum(str[i]))
    params->width = my_atoi(str + i);
  while (my_char_isnum(str[i]))
    ++i;
  if (str[i] == '*')
    params->is_size = 1;
  if (str[i] == '*')
    ++i;
  if (str[i] == '.')
    params->is_precision = 1;
  if (str[i] == '.' && str[i + 1] == '*')
    params->is_prec = 1;
  else if (str[i] == '.')
    params->precision = my_atoi(str + i + 1);
  return (i);
}

int	init_len(t_params *params, const char *str, unsigned int i)
{
  while (str[i] == '.' || str[i] == '*'
	 || (my_char_isnum(str[i])))
    ++i;
  if (str[i] == 'h' && str[i + 1] == 'h')
  {
    params->len = HH;
    i += 2;
  }
  else if (str[i] == 'l' && str[i + 1] == 'l')
  {
    params->len = LL;
    i += 2;
  }
  else if (str[i] == 'h' || str[i] == 'l' || str[i] == 'j'
           || str[i] == 'z' || str[i] == 't')
  {
    (str[i] == 'h') ? (params->len = H) : (0);
    (str[i] == 'l') ? (params->len = L) : (0);
    (str[i] == 'j') ? (params->len = J) : (0);
    (str[i] == 'z') ? (params->len = Z) : (0);
    (str[i] == 't') ? (params->len = T) : (0);
    ++i;
  }
  return (i);
}
