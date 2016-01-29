/*
** my_lstadd.c for listadd in /home/theis_p/lib/my
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Wed Dec 30 20:15:33 2015 Paul THEIS
** Last update Wed Dec 30 20:17:08 2015 Paul THEIS
*/

#include "./my.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
  if (alst && *alst && new)
    {
      new->next = (*alst);
      *alst = new;
    }
}
