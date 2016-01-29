/*
** my_strupcase.c for my_strupcase in /home/theis_p/git/Piscine_C_J06
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Mon Oct  5 15:24:36 2015 Paul THEIS
** Last update Mon Oct  5 15:24:46 2015 Paul THEIS
*/

#include "./my.h"

char    *my_strupcase(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
        str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
