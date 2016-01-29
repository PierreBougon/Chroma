/*
** print_char.c for printf in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 15:55:47 2015 theis_p
** Last update Sat Nov 14 15:39:53 2015 Paul THEIS
*/

#include "../../include/my_printf.h"

unsigned int	print_percent(t_tmp_arg *tmp, t_params *params,
			      unsigned int s_to_add,
			      unsigned int s_to_print)
{
  tmp->t_int = tmp->t_int;
  params->less = params->less;
  s_to_add = s_to_print;
  s_to_print = s_to_add;
  my_putchar(CPUR);
  return (1);
}

unsigned int	print_char(t_tmp_arg *tmp, t_params *params,
			   unsigned int s_to_add,
			   unsigned int s_to_print)
{
  unsigned int	cwrite;

  cwrite = 0;
  tmp->t_int = (unsigned char)tmp->t_int;
  s_to_print = 1;
  if ((int)s_to_print < params->width)
    s_to_add = params->width - s_to_print;
  cwrite = s_to_print + s_to_add;
  if (params->less == 1)
    my_putchar(tmp->t_int);
  if (params->width >= (int)s_to_print)
    add_space(s_to_add);
  if (params->less == 0)
    my_putchar(tmp->t_int);
  return (cwrite);
}
