/*
** print_octal.c for printf in /home/theis_p/my_printf
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov 14 16:14:24 2015 Paul THEIS
** Last update Sat Nov 14 16:14:27 2015 Paul THEIS
*/

#include "../../include/my_printf.h"

void	finish_octal(t_tmp_arg *tmp, t_params *params,
		     unsigned int s_to_add, unsigned int s_to_print)
{
  if (params->less == 1)
  {
    if (params->hash == 1)
      my_putstr("0");
    my_put_unsigned_nb(tmp->uint, s_to_print, "01234567");
  }
  if (params->width >= params->precision && params->zero == 1
      && params->is_precision == 0 && params->less == 0
      && params->width > (int)s_to_print)
    add_zero(s_to_add);
  else if (params->width >= (params->precision)
	   && params->width > (int)s_to_print)
    add_space(s_to_add);
  if (params->less == 0)
  {
    if (params->hash == 1)
      my_putstr("0");
    my_put_unsigned_nb(tmp->uint, s_to_print, "01234567");
  }
}

unsigned int	print_octal(t_tmp_arg *tmp, t_params *params,
			    unsigned int s_to_add, unsigned int s_to_print)
{
  unsigned int	cwrite;

  cwrite = 0;
  tmp->uint = convert_uint_len(tmp->uint, params);
  s_to_print = sizer_to_print(tmp, 'o');
  if ((int)s_to_print < params->precision)
    s_to_print = params->precision;
  if ((int)s_to_print < params->width)
    s_to_add = params->width - s_to_print;
  cwrite = s_to_print + s_to_add;
  if (params->hash == 1
      && (params->precision <= (int)sizer_to_print(tmp, 'o')))
    s_to_add = s_to_add - 1;
  if (params->hash == 1 && params->is_precision == 0
      && params->zero == 1)
  {
    my_putstr("0");
    params->hash = 0;
  }
  if (params->less == 1 || params->hash == 1)
    s_to_print = s_to_print - 1;
  finish_octal(tmp, params, s_to_add, s_to_print);
  return (cwrite);
}
