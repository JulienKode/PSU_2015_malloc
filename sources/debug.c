/*
** debug.c for  in /home/karst_j/PSU_2015_malloc/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Jan 28 09:52:29 2016 Julien Karst
** Last update Mon Feb 15 08:08:29 2016 Julien Karst
*/

#include	"libmy_malloc.h"

void		aff_t_virt(t_virt *tmp)
{
  if (tmp != NULL)
    {
      printf("structure[%p] pointer[%p] free[%c] f_next[%p]",
	     tmp, tmp->start, '0' + tmp->free, tmp->f_next);
      printf(" prev[%p] next[%p] size[%zu]\nLastList[%p] End[%p]\n",
	     tmp->prev, tmp->next, tmp->size, info.e_list, info.end);
    }
  else
    printf("NULL Element\n");
}

void		aff_table(int pos)
{
  t_virt	*tmp;
  int		i;

  i = 0;
  tmp = table[pos];
  printf("---SD aff_table[%d]---\n", pos);
  while (tmp != NULL)
    {
      printf("Elem[%d]\n", i);
      aff_t_virt(tmp);
      tmp = tmp->next;
      i++;
    }
  printf("---ED aff_table[%d]---\n", pos);
}

void		aff_all_table()
{
  int		i;

  i = 0;
  printf("---SD aff_all_table---\n");
  while (i < MAX)
    {
      aff_table(i);
      i++;
    }
  printf("---ED aff_all_table---\n");
}
