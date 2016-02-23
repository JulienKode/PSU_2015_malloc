/*
** list.c for  in /home/karst_j/PSU_2015_malloc/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Jan 28 09:52:29 2016 Julien Karst
** Last update Sun Feb 14 13:26:55 2016 Julien Karst
*/

#include	"libmy_malloc.h"

t_virt		*init_list(size_t size)
{
  int		ex;
  t_virt	*new;

  ex = know_sizeof_block(size);
  if ((new = take_to_table(ex)) == NULL)
    {
      new = size_alloc(align4(exp_two[ex] + sizeof(t_virt)));
      init_new_list(new, size);
      update_info();
    }
  new->size = size;
  new->f_next = NULL;
  return (new);
}

t_virt		*init_list_cpy(size_t size, t_virt *cpy)
{
  int		ex;
  t_virt	*new;
  size_t	i;

  i = 0;
  ex = know_sizeof_block(size + cpy->size);
  if ((new = take_to_table(ex)) == NULL)
    {
      new = size_alloc(align4(exp_two[ex] + sizeof(t_virt)));
      init_new_list(new, size + cpy->size);
      update_info();
    }
  new->size = size + cpy->size;
  while (i < cpy->size)
    {
      *(new->start + i) = *(cpy->start + i);
      i++;
    }
  new->f_next = NULL;
  return (new);
}

void		delete_list(t_virt *list)
{
  if (list)
    list->free = TRUE;
  if (list == info.e_list)
    {
      while (list->prev != NULL && list->free == TRUE)
        {
	  auto_delete(list);
	  list = list->prev;
        }
      delete_list_free(list);
    }
  else if (list)
    {
      if ((list->next && list->next->free == TRUE)
	  || (list->prev && list->prev->free == TRUE))
	list = fusion(list);
      add_to_table(know_sizeof_block(list->size), list);
    }
  return;
}
