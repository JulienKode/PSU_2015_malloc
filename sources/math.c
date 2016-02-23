/*
** math.c for  in /home/karst_j/PSU_2015_malloc/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Jan 28 09:52:29 2016 Julien Karst
** Last update Mon Feb 15 11:59:40 2016 Julien Karst
*/

#include	"libmy_malloc.h"

t_virt		*size_alloc(size_t size)
{
  int		alloc;
  int		rest;
  void		*res;
  res = NULL;
  rest = 0;
  alloc = 1;
  if (info.e_list)
    {
      rest = info.end - (void*)(info.e_list->start + info.e_list->size);
      if (rest < 0)
	rest = 0;
    }
  if (rest >= (int)size)
    return ((t_virt*)(info.e_list->start + info.e_list->size));
  while ( ((alloc*info.pagesize) + rest) < (int)size)
    alloc++;
  if ((res = sbrk(alloc*info.pagesize)) == NULL)
    exit(0);
  if (rest == 0)
    return (res);
  return (t_virt*)(info.e_list->start + info.e_list->size);
}

size_t		math_pow(size_t a, size_t b)
{
  size_t	i;
  size_t	res;

  if (b == 0)
    return (1);
  res = a;
  i = 0;
  while (i < b)
    {
      res *= a;
      i++;
    }
  return (res);
}

int		know_sizeof_block(size_t size)
{
  int		res;

  res = 0;
  while (exp_two[res] <= size)
    res++;
  return (res);
}
