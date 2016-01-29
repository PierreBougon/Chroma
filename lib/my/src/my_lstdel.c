/*
** my_lstdel.c for lstdel in /home/theis_p/lib/my/src
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Wed Dec 30 20:17:48 2015 Paul THEIS
** Last update Wed Dec 30 20:19:43 2015 Paul THEIS
*/

#include "./my.h"

void	my_lstdel(t_list **alst, void (*del)(void *, size_t))
{
  if (*alst && del)
    {
      ft_lstdel(&(*alst)->next, del);
      ft_lstdelone(alst, del);
    }
}
