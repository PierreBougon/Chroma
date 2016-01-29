/*
** list4.c for list4 in /home/goubea_t/graph/gfx_tekpaint
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Tue Jan 26 22:28:28 2016 Tristan goubeau
** Last update Tue Jan 26 22:31:01 2016 Tristan goubeau
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void		*front(list* llist)
{
  if (llist->size)
    return (llist->head->data);
  else
    return (NULL);
}

void		*get_index(list* llist, unsigned int index)
{
  node		*current;
  unsigned int	i;

  i = 0;
  if (!llist->size || index >= llist->size) {
    return (NULL);
  }

  current = llist->head;
  while (i < index)
    {
      current = current->next;
      i++;
    }

  return (current->data);
}

void*		back(list* llist)
{
  node *end;

  if (!llist->size)
    return (NULL);
  end = llist->head->prev;
  return (end->data);
}

int		is_empty(list* llist)
{
  if (llist->size == 0 && llist->head == NULL)
    return (1);
  else
    return (0);
}
