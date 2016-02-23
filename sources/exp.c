/*
** exp.c for  in /home/karst_j/PSU_2015_malloc/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Jan 28 09:52:29 2016 Julien Karst
** Last update Mon Feb 15 08:04:39 2016 Julien Karst
*/

#include	"libmy_malloc.h"

size_t		exp_two[MAX];

void		init_exp()
{
  int		i;

  i = 0;
  while (i < MAX)
    {
      exp_two[i] = (size_t)pow(2, (unsigned int)i);
      i++;
    }
  return;
}
