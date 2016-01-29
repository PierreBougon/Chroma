/*
** list5.c for list5 in /home/goubea_t/graph/gfx_tekpaint
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Tue Jan 26 22:31:29 2016 Tristan goubeau
** Last update Tue Jan 26 22:34:08 2016 Tristan goubeau
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "paint.h"

int	size(list* llist)
{
  return (llist->size);
}

int		find_occurrence(list* llist, const void* search,
				equal_op compare_func)
{
  node		*current;
  unsigned int	i;

  i = 0;
  current = llist->head;
  while (i < llist->size)
    {
      if (compare_func(search, current->data))
	return (1);
      current = current->next;
      i++;
    }
  return (0);
}

void		empty_list(list* llist, list_op free_func)
{
  node		*current;
  node		*next;
  unsigned int	i;

  i = 0;
  if (!llist->size)
    return ;
  current = llist->head;
  next = current->next;
  while (i < llist->size)
    {
      free_func(current->data);
      bunny_free(current);
      current = next;

      if (i < llist->size-1)
	next = current->next;
      i++;
    }

  llist->head = NULL;
  llist->size = 0;
}

void		traverse(list* llist, list_op do_func)
{
  unsigned int	i;
  node		*current;

  i = 0;
  current = llist->head;
  while (i < llist->size)
    {
      do_func(current->data);
      current = current->next;
      i++;
    }
}

void		dtraverse(list* llist, list_op2 do_func, struct s_data *data)
{
  unsigned int	i;
  node *current;

  i = 0;
  current = llist->head;
  while (i < llist->size)
    {
      do_func(current->data, data);
      current = current->next;
      i++;
    }
}
