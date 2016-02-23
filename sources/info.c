/*
** info.c for  in /home/karst_j/PSU_2015_malloc/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Jan 28 09:52:29 2016 Julien Karst
** Last update Mon Feb 15 11:56:29 2016 Julien Karst
*/

#include    "libmy_malloc.h"

void        init_info()
{
  if ((info.start = sbrk(0)) == NULL)
    exit(0);
  info.pagesize = getpagesize();
  init_exp();
  init_table();
  return;
}

void        update_info()
{
  if ((info.end = sbrk(0)) == NULL)
    exit(0);
  return;
}
