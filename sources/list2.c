/*
** list2.c for  in /home/karst_j/PSU_2015_malloc/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Jan 28 09:52:29 2016 Julien Karst
** Last update Tue Feb 23 21:11:41 2016 Julien Karst
*/

#include	"libmy_malloc.h"

t_virt		*last_elem(t_virt *list)
{
  while (list && list->next != NULL)
    list = list->next;
  return list;
}

t_virt		*found_ptr(void *ptr)
{
  t_virt	*list;

  list = NULL;
  if (ptr != NULL)
    list = ptr - (align4(sizeof(t_virt) - 8));
  if (list)
    return (list);
  return (NULL);
}

t_virt		*extend_size(t_virt *ptr, size_t size)
{
  size_alloc(align4(exp_two[know_sizeof_block(size)]
		    - exp_two[know_sizeof_block(ptr->size)]));
  ptr->size = size;
  return (ptr);
}

void		delete_list_free(t_virt *prev)
{
  int		rest;
  int		free;

  rest = 0;
  free = 0;
  prev->next = NULL;
  info.e_list = prev;
  rest = info.end - (void*)(prev->start + prev->size);
  while ( (free*info.pagesize) <= rest)
    free++;
  free--;
  if (free)
    {
      if (sbrk(-(free*info.pagesize)) == NULL)
	exit(0);
      update_info();
    }
}

void		init_new_list(t_virt *new, size_t size)
{
  new->free = FALSE;
  new->size = size;
  new->prev = info.e_list;
  if (new->prev != NULL)
    new->prev->next = new;
  else
    info.l_list = new;
  new->next = NULL;
  info.e_list = new;
}
