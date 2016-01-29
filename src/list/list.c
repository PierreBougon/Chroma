/*
** list.c for list5 in /home/goubea_t/graph/gfx_tekpaint
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Tue Jan 26 22:35:32 2016 Tristan goubeau
** Last update Tue Jan 26 22:40:35 2016 Tristan goubeau
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

static node	*create_node(void* data);

list		*create_list(void)
{
  list		*l;

  l = bunny_malloc(sizeof(list));
  l->head = NULL;
  l->size = 0;
  return (l);
}

static node	*create_node(void* data)
{
  node		*n;

  n = bunny_malloc(sizeof(node));
  n->data = data;
  n->prev = NULL;
  n->next = NULL;
  return (n);
}

void		push_front(list* llist, void* data)
{
  node		*n;
  node		*head;
  node		*prev;

  n = create_node(data);
  if (!llist->size)
    {
      n->next = n;
      n->prev = n;
    }
  else
    {
      head = llist->head;
      prev = head->prev;
      n->next = head;
      n->prev = head->prev;
      head->prev = n;
      prev->next = n;
    }
  llist->head = n;
  llist->size++;
}

void		push_back(list* llist, void* data)
{
  node		*n;
  node		*head;
  node		*prev;

  n = create_node(data);
  if (!llist->size)
    {
      n->next = n;
      n->prev = n;
      llist->head = n;
    }
  else
    {
      head = llist->head;
      prev = head->prev;
      n->next = head;
      n->prev = head->prev;
      head->prev = n;
      prev->next = n;
    }
  llist->size++;
}

int		remove_front(list* llist, list_op free_func)
{
  node		*head;
  node		*next;
  node		*prev;

  if (!llist->size)
    return (-1);
  head = llist->head;
  if (llist->size == 1)
    llist->head = NULL;
  else
    {
      next = head->next;
      prev = head->prev;
      llist->head = next;
      next->prev = prev;
      prev->next = next;
    }
  free_func(head->data);
  bunny_free(head);
  llist->size--;
  return (0);
}
