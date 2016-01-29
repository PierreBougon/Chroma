/*
** my_printf.c for printf in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 16:33:29 2015 theis_p
** Last update Sat Nov 14 16:14:58 2015 Paul THEIS
*/

#include "../include/my_printf.h"

unsigned int	find_good_param(t_params *params, va_list *arg_tmp,
				const char *str, unsigned int i)
{
  int		arg_cur;
  int		arg_to_find;

  ++i;
  arg_cur = 0;
  params->is_other = 1;
  arg_to_find = my_atoi(str + i);
  while (arg_cur < arg_to_find - 1)
  {
    va_arg(*arg_tmp, void *);
    ++arg_cur;
  }
  while (my_char_isnum(str[i++]));
  return (i);
}

unsigned int	sizer_to_print(t_tmp_arg *tmp, char c)
{
  if (c == 'd' || c == 'i')
    return (sizer_int(tmp->t_int));
  if (c == 'u')
    return (sizer_uint(tmp->uint));
  if (c == 'o')
    return (sizer_octal(tmp->uint));
  if (c == 'x' || c == 'X')
    return (sizer_hexa(tmp->uint));
  if (c == 'b')
    return (sizer_binary(tmp->uint));
  if (c == 's' || c == 'S')
    return (my_strlen(tmp->t_char));
  return (0);
}

unsigned int	print_it(t_tmp_arg *tmp, t_params *params, char c,
			 unsigned int schars)
{
  unsigned int	cw;
  t_flags gl_flagtab[11];

  init_flagtab(gl_flagtab);
  cw = 0;
  cw = gl_flagtab[is_flag(c, gl_flagtab)].flag_this(tmp, params, 0, 0);
  (c == 'n') ? (save_chars(tmp, schars)) : (0);
  return (cw);
}

unsigned int	check_print(t_struct_arg *args, const char *str,
				   unsigned int i, unsigned schars)
{
  t_params	*params;
  t_tmp_arg	*tmp;
  unsigned int	cwrite;

  if ((params = (t_params*)malloc(sizeof(*params))) == NULL ||
      (tmp = (t_tmp_arg*)malloc(sizeof(*tmp))) == NULL)
    return (i);
  init_params(params);
  if (is_params_nbr(str + i))
    i = find_good_param(params, &(args->arg_tmp), str, i);
  i = init_flags(params, str, i + 1);
  i = init_len(params, str, i);
  if (params->is_size == 1)
    params->width = va_arg(args->arg, int);
  if (params->is_prec == 1)
    params->precision = va_arg(args->arg, int);
  if (params->is_other == 1)
    stock_arg(&(args->arg_tmp), tmp, str[i]);
  else if (params->is_other == 0)
    stock_arg(&(args->arg), tmp, str[i]);
  cwrite = print_it(tmp, params, str[i], schars);
  free(params);
  free(tmp);
  return (cwrite);
}

int		my_printf(const char *format, ...)
{
  t_struct_arg	args;
  unsigned int	i;
  unsigned int	cwrite;

  i = 0;
  cwrite = 0;
  va_start(args.arg, format);
  while (format[i])
  {
    va_start(args.arg_tmp, format);
    if (format[i] == CPUR && is_to_convert(format + i) != 0)
    {
      cwrite += check_print(&args, format, i, cwrite) - 1;
      i += is_to_convert(format + i);
    }
    else
      my_putchar(format[i]);
    cwrite += 1;
    va_end(args.arg_tmp);
    ++i;
  }
  va_end(args.arg);
  return ((int)cwrite);
}
