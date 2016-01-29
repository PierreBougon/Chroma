/*
** my_revstr.c for my_revstr in /home/theis_p/git/Piscine_C_J06
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Mon Oct  5 10:53:32 2015 Paul THEIS
** Last update Tue Oct  6 15:23:11 2015 Paul THEIS
*/

#include "./my.h"

char    *my_revstr(char *str)
{
  int   len;
  int   i;
  char  tmp;

  i = 0;
  len = my_strlen(str);
  while (i < (len - len / 2))
    {
      tmp = *(str + i);
      *(str + i) = *(str + len - 1 - i);
      *(str + len - 1 - i) = tmp;
      i++;
    }
  return (str);
}
