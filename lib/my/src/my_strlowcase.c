/*
** my_strlowcase.c for my_strlowcase in /home/theis_p/git/Piscine_C_J06
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Mon Oct  5 15:37:42 2015 Paul THEIS
** Last update Mon Oct  5 15:37:53 2015 Paul THEIS
*/

#include "./my.h"

char    *my_strlowcase(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
        str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
