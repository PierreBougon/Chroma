/*
** print_str.c for printf in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 15:57:10 2015 theis_p
** Last update Sat Nov  7 15:57:11 2015 theis_p
*/

#include "../../include/my_printf.h"

void		put_n_str(char *str, unsigned int n)
{
  unsigned int	i;

  i = 0;
  while (str[i] && i < n)
  {
    my_putchar(str[i]);
    i = i + 1;
  }
}

unsigned int	print_str(t_tmp_arg *tmp, t_params *params,
			  unsigned int s_to_add, unsigned int s_to_print)
{
  unsigned int	cwrite;

  cwrite = 0;
  if (tmp->t_char == NULL)
  {
    my_putstr("(null)");
    return (0);
  }
  if (params->is_precision == 1
      && params->precision <= my_strlen(tmp->t_char))
    s_to_print = params->precision;
  else
    s_to_print = my_strlen(tmp->t_char);
  if ((int)s_to_print < params->width)
    s_to_add = params->width - s_to_print;
  cwrite = s_to_print + s_to_add;
  if (params->less == 1)
    put_n_str(tmp->t_char, s_to_print);
  if (params->width >= (int)s_to_print)
    add_space(s_to_add);
  if (params->less == 0)
    put_n_str(tmp->t_char, s_to_print);
  return (cwrite);
}
