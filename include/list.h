/*
** list.h for list in /home/theis_p/C-Doubly-Linked-List
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Wed Dec 30 19:09:27 2015 Paul THEIS
** Last update Tue Jan 26 22:09:07 2016 Tristan goubeau
*/

#ifndef LIST_H
#define LIST_H

# include "lapin.h"

typedef struct		lnode
{
  struct lnode		*prev;
  struct lnode		*next;
  void			*data;
}			node;

typedef struct		s_list
{
  struct lnode		*head;
  unsigned int		size;
}			list;

typedef void (*list_op)(void*);
typedef int (*list_pred)(const void*);
typedef int (*equal_op)(const void*, const void*);

/* Creating */
list	*create_list(void);

/* Adding */
void	push_front(list* llist, void* data);
void	push_back(list* llist, void* data);

/* Removing */
int	remove_front(list* llist, list_op free_func);
int	remove_index(list* llist, int index, list_op free_func);
int	remove_back(list* llist, list_op free_func);
int	remove_data(list* llist, const void* data, equal_op compare_func, list_op free_func);
int	remove_cond(list* llist, list_pred pred_func, list_op free_func);

/* Querying List */
void	*front(list* llist);
void	*back(list* llist);
void	*get_index(list* llist, unsigned int index);
int	is_empty(list* llist);
int	size(list* llist);

/* Searching */
int	find_occurrence(list *llist, const void* search, equal_op compare_func);

/* Freeing */
void	empty_list(list *llist, list_op free_func);

/* Traversal */
void	traverse(list *llist, list_op do_func);

#endif
