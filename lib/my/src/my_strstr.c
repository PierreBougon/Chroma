/*
** my_strstr.c for my_strstr in /home/theis_p/my_printf
** 
** Made by theis_p
** Login   <theis_p@epitech.net>
** 
** Started on  Sat Nov  7 18:28:25 2015 theis_p
** Last update Sat Nov  7 18:28:45 2015 theis_p
*/

#include "./my.h"

int     get_flag(char *str, char *to_find)
{
  int   i;
  int   j;
  int   len_str;
  int   len_find;
  int   flag;

  i = 0;
  j = 0;
  len_str = my_strlen(str);
  len_find = my_strlen(str);
  while (i < len_str)
    {
      while (j < len_find)
        {
          if (str[i + j] != to_find[j])
            break;
          j = j + 1;
        }
      if (j == len_find)
        {
          flag = 1;
        }
      i = i + 1;
    }
  return (flag);
}

int     get_max(char *str, char *to_find)
{
  int   i;
  int   j;
  int   len_str;
  int   len_find;
  int   max;

  i = 0;
  j = 0;
  len_str = my_strlen(str);
  len_find = my_strlen(str);
  while (i < len_str)
    {
      while (j < len_find)
        {
          if (str[i + j] != to_find[j])
            break;
          j = j + 1;
        }
      if (j == len_find)
        {
          max = i;
        }
      i = i + 1;
    }
  return (max);
}

char    *my_strstr(char *str, char *to_find)
{
  int   flag;
  int   max;

  flag = get_flag(str, to_find);
  max = get_max(str, to_find);
  if (flag == 1)
    return (str + max);
  else
    return (0);
}
