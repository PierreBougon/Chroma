/*
** my_printf.h for printf in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 16:57:19 2015 theis_p
** Last update Sat Nov 14 15:54:48 2015 Paul THEIS
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "../../my.h"
# include "struct.h"
# include "print.h"
# include "sizer.h"

# define HH	1
# define H	2
# define LL	3
# define L	4
# define J	5
# define Z	6
# define T	7
# define CPUR	'%'

void		add_space(unsigned int size_to_add);
void		add_zero(unsigned int size_to_add);
unsigned long	convert_hexa_len(unsigned long nb, t_params *params);
void		my_putnbr_prec(long nb, int precision, int size_nb, int is_plus);
void		my_put_unsigned_nb(unsigned long nb, int precision, char *base);
unsigned int	sizer_to_print(t_tmp_arg *tmp, char c);
unsigned long	convert_uint_len(unsigned long nb, t_params *params);
void		init_params(t_params *params);
int		init_flags(t_params *params, const char *str, unsigned int i);
int		init_len(t_params *params, const char *str, unsigned int i);
void		stock_arg(va_list *arg, t_tmp_arg *tmp, char c);
unsigned int	is_to_convert(const char *str);
unsigned int	save_chars(t_tmp_arg *tmp, unsigned int schars);
unsigned int	print_percent(t_tmp_arg *tmp, t_params *params,
			      unsigned int s_to_add, unsigned int s_to_print);
int		is_params_nbr(const char *str);
int		is_flag(char c, t_flags *gl_flagtab);
  void		init_flagtab(t_flags *gl_flagtab);

#endif /* !MY_PRINTF_H_ */
