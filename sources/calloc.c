/*
** calloc.c for  in /home/karst_j/PSU_2015_malloc/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Jan 28 09:52:29 2016 Julien Karst
** Last update Feb 12 10:3:32 2016 Julien Karst
*/

#include        "libmy_malloc.h"

void            *calloc(size_t nmemb, size_t size)
{
    size_t      fsize;
    void        *res;

    if (nmemb == 0 || size == 0)
        return (NULL);
    fsize = nmemb * size;
    res = malloc(fsize);
    if (res != NULL)
        memset(res, 0, fsize);
    return (res);
}
