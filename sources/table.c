/*
** table.c for  in /home/karst_j/PSU_2015_malloc/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Jan 28 09:52:29 2016 Julien Karst
** Last update Mon Feb 15 08:13:31 2016 Julien Karst
*/

#include	"libmy_malloc.h"

t_virt		*table[MAX];

void		init_table()
{
  int		c;

  c = 0;
  while (c < MAX)
    {
      table[c] = NULL;
      c++;
    }
  return;
}

void		add_to_table(int pos, t_virt *elem)
{
    if (bad_elem(elem, pos) == 1)
        return;
  elem->f_next = NULL;
  if (table[pos] == NULL)
    table[pos] = elem;
  else
    {
      elem->f_next = table[pos];
      table[pos] = elem;
    }
  return;
}

t_virt		*take_to_table(int pos)
{
  t_virt	*res;

  res = table[pos];
  if (res != NULL)
    {
      res->free = FALSE;
      table[pos] = res->f_next;
      if (bad_elem(res, pos) == 1)
        return (take_to_table(pos));
    }
  else
    table[pos] = NULL;
  return (res);
}

void		auto_delete(t_virt *tmp)
{
  int		pw;
  t_virt	*sp;
  t_virt	*last;

  if (tmp)
    {
      pw = know_sizeof_block(tmp->size);
      sp = table[pw];
      last = sp;
      while (sp != NULL)
        {
	  if (sp == tmp)
            {
	      if (last == sp)
		table[pw] = last->f_next;
	      last->f_next = sp->f_next;
	      sp->free = FALSE;
	      return;
            }
	  last = sp;
	  sp = sp->f_next;
        }
    }
  return;
}

int         bad_elem(t_virt *res, int pos)
{
    if (res)
    {
        if (res->size > exp_two[pos - 1]
            || res->size <= exp_two[pos - 1]
            || (res->free != TRUE && res->free != FALSE))
            return (1);
        if (res->f_next > info.e_list
	    || res->next > info.e_list
	    || res->prev > info.e_list)
            return (1);
        if (res->size > exp_two[MAX - 1])
            return (1);
    }
    else
        return (1);
    return (0);
}
