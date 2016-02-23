/*
** realloc.c for  in /home/karst_j/PSU_2015_malloc/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Jan 28 09:52:37 2016 Julien Karst
** Last update Feb 14 11:46:54 2016 Julien Karst
*/

#include    "libmy_malloc.h"

void        *realloc(void *ptr, size_t size)
{
    t_virt  *elem;
    t_virt  *res;
    void    *r;

    r = NULL;
    if ((int)size < 0)
        r = NULL;
    if (info.pagesize == -1)
        init_info();
    elem = found_ptr(ptr);
    if (ptr == NULL)
        r = malloc(size);
    else if (size == 0 && ptr != NULL)
        free(ptr);
    else if (elem != NULL)
    {
        pthread_mutex_lock(&(info.mu));
        if (elem == info.e_list)
            res = sub_realloc_last_elem(elem, size);
        else
            res = sub_realloc_elem(elem, size);
        r = res->start;
        pthread_mutex_unlock(&(info.mu));
    }
    return (r);
}

t_virt      *sub_realloc_last_elem(t_virt *elem, size_t size)
{
    t_virt  *res;

    res = extend_size(elem, size);
    return (res);
}

t_virt      *sub_realloc_elem(t_virt *elem, size_t size)
{
    t_virt  *res;

    res = init_list_cpy(size, elem);
    delete_list(elem);
    return (res);
}
