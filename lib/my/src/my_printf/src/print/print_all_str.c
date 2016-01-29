/*
** print_all_str.c for printf in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 15:55:05 2015 theis_p
** Last update Sat Nov  7 15:55:07 2015 theis_p
*/

#include "../../include/my_printf.h"

unsigned int	put_n_all_str(char *str, unsigned int n)
{
  unsigned int	i;
  unsigned int	cwrite;

  i = 0;
  while (str[i] && i < n)
  {
    if (str[i] >= 32 && str[i] <= 126)
    {
      cwrite = cwrite + 1;
      my_putchar(str[i]);
    }
    else
    {
      cwrite += 4;
      my_putchar('\\');
      my_put_unsigned_nb(str[i], 3, "01234567");
    }
    ++i;
  }
  return (cwrite);
}

unsigned int	print_all_str(t_tmp_arg *tmp, t_params *params,
			      unsigned int s_to_add,
			      unsigned int s_to_print)
{
  unsigned int	cwrite;

  cwrite = 0;
  if (params->is_precision == 1
      && params->precision <= my_strlen(tmp->t_char))
    s_to_print = params->precision;
  else
    s_to_print = my_strlen(tmp->t_char);
  if ((int)s_to_print < params->width)
    s_to_add = params->width - s_to_print;
  if (params->less == 1)
    cwrite = put_n_all_str(tmp->t_char, s_to_print);
  if (params->width >= (int)s_to_print)
    add_space(s_to_add);
  if (params->less == 0)
    cwrite = put_n_all_str(tmp->t_char, s_to_print);
  return (cwrite);
}
