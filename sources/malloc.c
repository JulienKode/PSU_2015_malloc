/*
** malloc.c for  in /home/karst_j/PSU_2015_malloc/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Jan 28 09:52:29 2016 Julien Karst
** Last update Sun Feb 14 11:19:31 2016 Julien Karst
*/

#include "libmy_malloc.h"

t_info              info =
{
    NULL,
    NULL,
    PTHREAD_MUTEX_INITIALIZER,
    NULL,
    NULL,
    -1,
    NULL,
    NULL
};

void                *malloc(size_t size)
{
    t_virt          *res;

    if ((int)size < 0)
        return (NULL);
    pthread_mutex_lock(&(info.mu));
    if (info.pagesize == -1)
        init_info();
    res = init_list(size);
    pthread_mutex_unlock(&(info.mu));
    return (res->start);
}
