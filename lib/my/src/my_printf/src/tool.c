/*
** tool.c for printf in /home/theis_p/my_printf/lib/my/src/my_printf/src
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 16:28:58 2015 theis_p
** Last update Sat Nov 14 15:54:07 2015 Paul THEIS
*/

#include "../include/my_printf.h"

void	add_space(unsigned int size_to_add)
{
  while (size_to_add > 0)
  {
    write(1, " ", 1);
    --size_to_add;
  }
}

void	add_zero(unsigned int size_to_add)
{
  while (size_to_add > 0)
  {
    write(1, "0", 1);
    --size_to_add;
  }
}

void	my_putnbr_prec(long nb, int precision, int is_space, int is_plus)
{
  int	size_nb;

  size_nb = sizer_int(nb);
  if (nb < 0)
  {
    my_putchar('-');
    nb = -nb;
  }
  else if (nb >= 0 && (is_space == 1 || is_plus == 1))
  {
    if (is_plus == 1)
      my_putchar('+');
    --precision;
  }
  while (precision > size_nb)
  {
    my_putchar('0');
    --precision;
  }
  if (nb >= 10)
    my_putnbr_prec(nb / 10, 0, size_nb, 0);
  my_putchar((nb % 10) + '0');
}

int     is_flag(char c, t_flags *gl_flagtab)
{
  int   n;

  n = 0;
  while (n < 10)
    {
      if (c ==  gl_flagtab[n].flag)
	return (n);
      ++n;
    }
  return (n);
}

void            init_flagtab(t_flags *gl_flagtab)
{
  gl_flagtab[0].flag = 'd';
  gl_flagtab[0].flag_this = &print_int;
  gl_flagtab[1].flag = 'i';
  gl_flagtab[1].flag_this = &print_int;
  gl_flagtab[2].flag = 'u';
  gl_flagtab[2].flag_this = &print_uint;
  gl_flagtab[3].flag = 'x';
  gl_flagtab[3].flag_this = &print_little_hexa;
  gl_flagtab[4].flag = 'X';
  gl_flagtab[4].flag_this = &print_large_hexa;
  gl_flagtab[5].flag = 'o';
  gl_flagtab[5].flag_this = &print_octal;
  gl_flagtab[6].flag = 's';
  gl_flagtab[6].flag_this = &print_str;
  gl_flagtab[7].flag = CPUR;
  gl_flagtab[7].flag_this = &print_percent;
  gl_flagtab[8].flag = 'S';
  gl_flagtab[8].flag_this = &print_all_str;
  gl_flagtab[9].flag = 'p';
  gl_flagtab[9].flag_this = &print_ptr;
  gl_flagtab[10].flag = 'b';
  gl_flagtab[10].flag_this = &print_binary;
}
