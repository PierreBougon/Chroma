/*
** my_getnbr.c for my_getnbr in /home/theis_p/git/Piscine_C_J04
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Thu Oct  1 11:45:06 2015 Paul THEIS
** Last update Tue Oct 13 19:25:23 2015 Paul THEIS
*/

#include "./my.h"

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;
  int	div;

  i = 0;
  nbr = 1;
  div = 0;
  while (str[i])
    {
      if (str[i] == '-')
	nbr = - nbr;
      if (str[i] >= 48 && str[i] <= 57)
	{
	  while (str[i] && str[i] >= 48 && str[i] <= 57)
	    {
	      if (div > div * 10 + (str[i] - 48))
		return (0);
	      div = div * 10 + (str[i++] - 48);
	    }
	  return (div * nbr);
	}
      i++;
    }
  return (0);
}
