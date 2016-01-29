/*
** list2.c for list2 in /home/goubea_t/graph/gfx_tekpaint
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Tue Jan 26 20:26:15 2016 Tristan goubeau
** Last update Tue Jan 26 22:27:21 2016 Tristan goubeau
*/

#include <stdlib.h>
#include <stdio.h>
#include "paint.h"

int	remove_index(list* llist, int index, list_op free_func)
{
  node *current;
  int	i;

  i = 0;
  if (!llist->size)
    return (-1);
  current = llist->head;
  while (i < index)
    {
      current = current->next;
      i++;
    }
  if (llist->size == 1)
    llist->head = NULL;
  else
    {
      node *next = current->next;
      node *prev = current->prev;
      prev->next = next;
      next->prev = prev;
    }
  free_func(current->data);
  bunny_free(current);
  llist->size--;
  return (0);
}

int	remove_back(list* llist, list_op free_func)
{
  node *head;
  node *tbr;
  node *nb;

  if (!llist->size)
    return (-1);
  head = llist->head;
  tbr = head->prev;
  nb = tbr->prev;
  if (llist->size == 1)
    llist->head = NULL;
  else
    {
      head->prev = nb;
      nb->next = head;
    }
  free_func(tbr->data);
  bunny_free(tbr);
  llist->size--;
  return (0);
}

int	remove_data(list* llist, const void* data,
		equal_op compare_func, list_op free_func)
{
  node	*current;
  node	*next;
  node	*prev;
  int	is_head;
  unsigned int	i;
  int	removed;

  i = 0;
  removed = 0;
  if (!llist->size)
    return (removed);
  current = llist->head;
  next = current->next;
  prev = current->prev;
  is_head = 1;
  while (i < llist->size)
    {
      if (compare_func(data, current->data))
	{
	  if (is_head) llist->head = next;
	  next->prev = prev;
	  prev->next = next;
	  free_func(current->data);
	  bunny_free(current);
	  current = next;
	  removed++;
	}
      else
	{
	  is_head = 0;
	  current = current->next;
	}
      if (llist->size > 1)
	{
	  next = current->next;
	  prev = current->prev;
	}
       i++;
    }
  llist->size-=removed;
  if (!llist->size) llist->head = NULL;
  return (removed);
}

int	remove_cond(list* llist, list_pred pred_func,
		    list_op free_func)
{
  int removed;
  int is_head;
  unsigned int i;
  node *current;
  node *next;
  node *prev;

  if (!llist->size)
    return (0);
  removed = 0;
  current = llist->head;
  next = current->next;
  prev = current->prev;
  is_head = 1;
  i = 0;
  while (i < llist->size) {
    if (pred_func(current->data)) {
      if (is_head) llist->head = next;

      next->prev = prev;
      prev->next = next;

      free_func(current->data);
      bunny_free(current);

      current = next;

      removed++;
    }
    else
      {
	is_head = 0;
	current = current->next;
      }
    if (llist->size > 0) {
      next = current->next;
      prev = current->prev;
    }
    i++;
  }
  llist->size-=removed;
  if (!llist->size)
    llist->head = NULL;
  return (removed);
}
