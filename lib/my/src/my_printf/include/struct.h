/*
** struct.h for printf in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 17:07:03 2015 theis_p
** Last update Sat Nov 14 15:11:01 2015 Paul THEIS
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct	s_params
{
  int		is_other;
  int		less;
  int		plus;
  int		space;
  int		hash;
  int		zero;
  int		width;
  int		is_size;
  int		is_precision;
  int		precision;
  int		is_prec;
  int		len;
}               t_params;

typedef struct	s_struct_arg
{
  va_list	arg;
  va_list	arg_tmp;
}		t_struct_arg;

typedef struct		s_tmp_arg
{
  unsigned long	uint;
  long		t_int;
  char			*t_char;
  void			*ptr;
  unsigned int		*schars;
}			t_tmp_arg;

typedef struct  s_flags
{
  char          flag;
  unsigned int	(*flag_this)(t_tmp_arg *tmp, t_params *params,
			      unsigned int s_to_add,
			      unsigned int s_to_print);
}               t_flags;

#endif /* !STRUCT_H_ */
