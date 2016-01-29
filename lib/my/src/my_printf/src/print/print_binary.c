/*
** print_binary.c for printf in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 15:55:33 2015 theis_p
** Last update Sat Nov  7 15:55:35 2015 theis_p
*/

#include "../../include/my_printf.h"

unsigned int	print_binary(t_tmp_arg *tmp, t_params *params,
			     unsigned int s_to_add,
			     unsigned int s_to_print)
{
  unsigned int	cwrite;

  cwrite = 0;
  tmp->uint = convert_uint_len(tmp->uint, params);
  s_to_print = sizer_to_print(tmp, 'b');
  if ((int)s_to_print < params->precision)
    s_to_print = params->precision;
  if ((int)s_to_print < params->width)
    s_to_add = params->width - s_to_print;
  cwrite = s_to_print + s_to_add;
  if (params->less == 1)
    my_put_unsigned_nb(tmp->uint, s_to_print, "01");
  if (params->width >= params->precision && params->zero == 1
      && params->is_precision == 0 && params->less == 0
      && params->width > (int)s_to_print)
    add_zero(s_to_add);
  else if (params->width >= (params->precision)
	   && params->width > (int)s_to_print)
    add_space(s_to_add);
  if (params->less == 0)
    my_put_unsigned_nb(tmp->uint, s_to_print, "01");
  return (cwrite);
}
