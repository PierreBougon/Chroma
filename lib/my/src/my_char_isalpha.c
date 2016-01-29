/*
** my_char_isalpha.c for my_char_isalpha in /home/theis_p/my_printf/lib/my/src
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov  6 09:49:47 2015 theis_p
** Last update Fri Nov  6 09:58:03 2015 theis_p
*/

int	my_char_isalpha(char c)
{
  if (c >= 'A' && c <= 'Z')
      return (1);
  else if (c >= 'a' && c <= 'z')
      return (1);
  else
      return (0);
}
