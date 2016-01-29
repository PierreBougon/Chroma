/*
** print.h for printf in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 16:58:11 2015 theis_p
** Last update Thu Nov 12 12:13:40 2015 Paul THEIS
*/

#ifndef PRINT_H_
# define PRINT_H_

unsigned int		print_int(t_tmp_arg *tmp, t_params *params,
				  unsigned int s_to_add,
				  unsigned int s_to_print);
unsigned int		print_uint(t_tmp_arg *tmp, t_params *params,
				   unsigned int s_to_add,
				   unsigned int s_to_print);
unsigned int		print_char(t_tmp_arg *tmp, t_params *params,
				   unsigned int s_to_add,
				   unsigned int s_to_print);
unsigned int		print_large_hexa(t_tmp_arg *tmp, t_params *params,
					 unsigned int s_to_add,
					 unsigned int s_to_print);
unsigned int		print_little_hexa(t_tmp_arg *tmp, t_params *params,
					  unsigned int s_to_add,
					  unsigned int s_to_print);
unsigned int		print_octal(t_tmp_arg *tmp, t_params *params,
				    unsigned int s_to_add,
				    unsigned int s_to_print);
unsigned int		print_ptr(t_tmp_arg *tmp, t_params *params,
				  unsigned int s_to_add,
				  unsigned int s_to_print);
unsigned int		print_str(t_tmp_arg *tmp, t_params *params,
				  unsigned int s_to_add,
				  unsigned int s_to_print);
unsigned int		print_all_str(t_tmp_arg *tmp, t_params *params,
				      unsigned int s_to_add,
				      unsigned int s_to_print);
unsigned int		print_binary(t_tmp_arg *tmp, t_params *params,
				      unsigned int s_to_add,
				      unsigned int s_to_print);

#endif /* !PRINT_H_ */
