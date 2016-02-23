/*
** free.c for  in /home/karst_j/PSU_2015_malloc/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Jan 28 09:52:47 2016 Julien Karst
** Last update Feb 12 10:5:3 2016 Julien Karst
*/

#include "libmy_malloc.h"

void        free(void *ptr)
{
    if (ptr == NULL)
        return;
    pthread_mutex_lock(&(info.mu));
    if (info.pagesize == -1)
        init_info();
    if (ptr != NULL)
        delete_list(found_ptr(ptr));
    pthread_mutex_unlock(&(info.mu));
}
