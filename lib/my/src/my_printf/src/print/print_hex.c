/*
** print_hex.c for printf in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 15:56:14 2015 theis_p
** Last update Sat Nov  7 17:14:22 2015 theis_p
*/

#include "../../include/my_printf.h"

unsigned long	convert_hexa_len(unsigned long nb,
					    t_params *params)
{
  if (params->len == HH)
    return ((unsigned char)nb);
  if (params->len == H)
    return ((unsigned short)nb);
  if (params->len == L)
    return ((unsigned long)nb);
  if (params->len == LL)
    return ((unsigned long)nb);
  if (params->len == Z)
    return ((size_t)nb);
  if (params->len == J)
    return ((intmax_t)nb);
  if (params->len == T)
    return ((ptrdiff_t)nb);
  return ((unsigned int)nb);
}

void	finish_little_hexa(t_tmp_arg *tmp, t_params *params,
				  unsigned int s_to_add,
				  unsigned int s_to_print)
{
  if (params->less == 1)
  {
    if (params->hash == 1 && tmp->uint != 0)
      my_putstr("0x");
    my_put_unsigned_nb(tmp->uint, s_to_print, "0123456789abcdef");
  }
  if (params->width >= params->precision && params->zero == 1
      && params->is_precision == 0 && params->less == 0
      && params->width > (int)s_to_print)
    add_zero(s_to_add);
  else if (params->width >= (params->precision) &&
	   params->width > (int)s_to_print)
    add_space(s_to_add);
  if (params->less == 0)
  {
    if (params->hash == 1 && tmp->uint != 0)
      my_putstr("0x");
    my_put_unsigned_nb(tmp->uint, s_to_print, "0123456789abcdef");
  }
}

unsigned int	print_little_hexa(t_tmp_arg *tmp, t_params *params,
				  unsigned int s_to_add,
				  unsigned int s_to_print)
{
  unsigned int	cwrite;

  cwrite = 0;
  tmp->uint = convert_hexa_len(tmp->uint, params);
  s_to_print = sizer_to_print(tmp, 'x');
  if ((int)s_to_print < params->precision)
    s_to_print = params->precision;
  if ((int)s_to_print < params->width)
    s_to_add = params->width - s_to_print;
  cwrite = s_to_print + s_to_add;
  if (params->hash == 1)
    s_to_add = s_to_add - 2;
  if (params->hash == 1 && params->is_precision == 0
      && params->zero == 1)
  {
    my_putstr("0x");
    params->hash = 0;
  }
  finish_little_hexa(tmp, params, s_to_add, s_to_print);
  return (cwrite);
}
