/*
** my_putnbr_base.c for my_putnbr_base in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 17:08:15 2015 theis_p
** Last update Sat Nov  7 17:08:18 2015 theis_p
*/

#include "./my.h"

int		my_putnbr_base(int n, char *base)
{
  int		r;
  int		d;
  int		base_n;
  int		i;

  i = 0;
  base_n = my_strlen(base);
  if (n < 0)
    {
      my_putchar('-');
      i++;
      n = -n;
    }
  d = 1;
  while ((n / d) >= base_n)
    d = d * base_n;
  while (d > 0)
    {
      r = (n /d) % base_n;
      my_putchar(base[r]);
      i++;
      d = d / base_n;
    }
  return (i);
}

int		my_putnbr_base_unsigned(unsigned n, char *base)
{
  unsigned int	r;
  unsigned int	d;
  unsigned int	base_n;
  unsigned int	i;

  i = 0;
  base_n = my_strlen(base);
  d = 1;
  while ((n / d) >= base_n)
    d = d * base_n;
  while (d > 0)
    {
      r = (n /d) % base_n;
      my_putchar(base[r]);
      i++;
      d = d / base_n;
    }
  return (i);
}

int			my_putnbr_base_addr(unsigned long n, char *base)
{
  unsigned long		r;
  unsigned long		d;
  unsigned int		base_n;
  unsigned int		i;

  i = 0;
  base_n = my_strlen(base);
  d = 1;
  while ((n / d) >= base_n)
    d = d * base_n;
  while (d > 0)
    {
      r = (n /d) % base_n;
      my_putchar(base[r]);
      i++;
      d = d / base_n;
    }
  return (i);
}
