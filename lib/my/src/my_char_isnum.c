/*
** my_char_isnum.c for my_char_isnum in /home/theis_p/my_printf/lib/my/src
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov  6 09:55:42 2015 theis_p
** Last update Fri Nov  6 10:48:44 2015 theis_p
*/

int	my_char_isnum(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}
