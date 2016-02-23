/*
** list3.c for  in /home/karst_j/PSU_2015_malloc/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Jan 28 09:52:29 2016 Julien Karst
** Last update Sun Feb 14 11:22:41 2016 Julien Karst
*/

#include	"libmy_malloc.h"

t_virt		*fusion(t_virt *tmp)
{
  info.next = tmp;
  info.prev = tmp;
  while (info.next->next != NULL && info.next->free == TRUE)
    info.next = info.next->next;
  while (info.prev->prev != NULL &&  info.next->free == TRUE)
     info.prev =  info.prev->prev;
  if (info.prev && info.prev->free == FALSE)
    info.prev = info.prev->next;
  if (info.next && info.next->free == FALSE)
    info.next = info.next->prev;
  if (info.next != info.prev)
    {
      info.prev->next = info.next->next;
      info.next->next->prev = info.prev;
      info.prev->size = (void*)(info.next->start
				+ info.next->size) - (void*)info.prev->start;
      if (info.next == info.e_list)
        {
	  delete_list_free(info.prev);
	  return (NULL);
        }
      else
	return (info.prev);
    }
  return (tmp);
}
