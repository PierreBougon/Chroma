/*
** print_uint.c for printf in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 15:57:23 2015 theis_p
** Last update Sat Nov  7 17:15:29 2015 theis_p
*/

#include "../../include/my_printf.h"

unsigned long	convert_uint_len(unsigned long nb,
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
    return ((uintmax_t)nb);
  if (params->len == T)
    return ((ptrdiff_t)nb);
  return ((unsigned int)nb);
}

void	my_put_unsigned_nb(unsigned long nb, int precision, char *base)
{
  unsigned long	size_base;
  int	size_nb;

  size_base = my_strlen(base);
  if (size_base == 10)
    size_nb = sizer_uint(nb);
  else if (size_base == 16)
    size_nb = sizer_hexa(nb);
  else if (size_base == 8)
    size_nb = sizer_octal(nb);
  else if (size_base == 2)
    size_nb = sizer_binary(nb);
  while (precision > size_nb)
  {
    my_putchar('0');
    precision = precision - 1;
  }
  if (nb >= size_base)
    my_put_unsigned_nb(nb / size_base, 0, base);
  my_putchar(base[(int)(nb % size_base)]);
}

unsigned int	print_uint(t_tmp_arg *tmp, t_params *params,
			   unsigned int s_to_add, unsigned int s_to_print)
{
  unsigned int	cwrite;

  cwrite = 0;
  tmp->uint = convert_uint_len(tmp->uint, params);
  s_to_print = sizer_to_print(tmp, 'u');
  if ((int)s_to_print < params->precision)
    s_to_print = params->precision;
  if ((int)s_to_print < params->width)
    s_to_add = params->width - s_to_print;
  cwrite = s_to_print + s_to_add;
  if (params->less == 1)
    my_put_unsigned_nb(tmp->uint, s_to_print, "0123456789");
  if (params->width >= params->precision && params->zero == 1
      && params->is_precision == 0 && params->less == 0
      && params->width > (int)s_to_print)
    add_zero(s_to_add);
  else if (params->width >= (params->precision) &&
	   params->width > (int)s_to_print)
    add_space(s_to_add);
  if (params->less == 0)
    my_put_unsigned_nb(tmp->uint, s_to_print, "0123456789");
  return (cwrite);
}
