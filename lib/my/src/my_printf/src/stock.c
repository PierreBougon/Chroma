/*
** stock.c for printf in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 15:54:18 2015 theis_p
** Last update Sat Nov  7 15:54:27 2015 theis_p
*/

#include "../include/my_printf.h"

void	stock_arg(va_list *arg, t_tmp_arg *tmp, char c)
{
  tmp->uint = 0;
  tmp->t_int = 0;
  tmp->t_char = NULL;
  tmp->ptr = NULL;
  tmp->schars = NULL;

  if (c == 's' || c == 'S')
    tmp->t_char = va_arg(*arg, char *);
  else if (c == 'p')
    tmp->ptr = va_arg(*arg, void *);
  else if (c == 'c' || c == 'd' || c == 'i')
    tmp->t_int = va_arg(*arg, long);
  else if (c == 'n')
    tmp->schars = va_arg(*arg, unsigned int *);
  else
    tmp->uint = va_arg(*arg, unsigned long);
}
