/*
** print_int.c for printf in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 15:56:43 2015 theis_p
** Last update Sat Nov  7 17:15:17 2015 theis_p
*/

#include "../../include/my_printf.h"

long	convert_int_len(long nb, t_params *params)
{
  if (params->len == HH)
    return ((char)nb);
  if (params->len == H)
    return ((short)nb);
  if (params->len == L)
    return ((long)nb);
  if (params->len == LL)
    return ((long)nb);
  if (params->len == Z)
    return ((size_t)nb);
  if (params->len == J)
    return ((intmax_t)nb);
  if (params->len == T)
    return ((ptrdiff_t)nb);
  return ((int)nb);
}

void	begin_int(t_tmp_arg *tmp, t_params *params,
		  unsigned int *s_to_add, unsigned int *s_to_print)
{
  tmp->t_int = convert_int_len(tmp->t_int, params);
  *s_to_print = sizer_to_print(tmp, 'd');
  if ((int)*s_to_print < params->precision)
    *s_to_print = params->precision;
  if (params->space == 1 && params->plus == 0 && tmp->t_int >= 0)
    my_putchar(' ');
  if (tmp->t_int < 0 && params->precision >= (int)*s_to_print)
    *s_to_print = *s_to_print + 1;
  if ((params->plus == 1 || params->space == 1) && tmp->t_int >= 0)
    *s_to_print = *s_to_print + 1;
  if ((int)*s_to_print < params->width)
    *s_to_add = params->width - *s_to_print;
  if (params->less == 1)
    my_putnbr_prec(tmp->t_int, *s_to_print, params->space, params->plus);
}

void	inter_int(t_tmp_arg *tmp, t_params *params,
		  unsigned int *s_to_add, unsigned int *s_to_print)
{
  if (params->zero == 1 && params->is_precision == 0 && tmp->t_int < 0
      && params->less == 0)
  {
    my_putchar('-');
    tmp->t_int = -(tmp->t_int);
    *s_to_print = *s_to_print - 1;
    params->plus = 0;
  }
  else if (params->zero == 1 && params->plus == 1 && params->less == 0
    && tmp->t_int >= 0)
  {
    if (params->less == 1)
      my_putchar('+');
    if (params->less == 1)
      params->plus = 0;
    if (params->zero == 1 && params->plus == 0)
      *s_to_add = *s_to_add + 1;
    if (params->space == 0)
      *s_to_add = *s_to_add - 1;
  }
}

unsigned int	print_int(t_tmp_arg *tmp, t_params *params,
			  unsigned int s_to_add, unsigned int s_to_print)
{
  unsigned int	cwrite;

  cwrite = 0;
  begin_int(tmp, params, &s_to_add, &s_to_print);
  cwrite = s_to_print + s_to_add;
  inter_int(tmp, params, &s_to_add, &s_to_print);
  if (params->width >= params->precision && params->zero == 1
      && params->is_precision == 0 && params->less == 0
      && params->width > (int)s_to_print)
    add_zero(s_to_add);
  else if (params->width >= (params->precision) &&
	   params->width > (int)s_to_print)
    add_space(s_to_add);
  if (params->less == 0)
    my_putnbr_prec(tmp->t_int, s_to_print, params->space, params->plus);
  return (cwrite);
}
