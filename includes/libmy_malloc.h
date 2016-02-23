/*
** libmy_malloc.h for  in /home/karst_j/PSU_2015_malloc/includes
**
** Login   <karst_j@epitech.net>
**
** Started on  Thu Jan 28 10:02:29 2016 Julien Karst
** Last update Mon Feb 15 11:45:53 2016 Julien Karst
*/

#ifndef                 LIBMY_MALLOC_H_
# define                LIBMY_MALLOC_H_

#include                <string.h>
#include                <unistd.h>
#include                <stdio.h>
#include                <pthread.h>
#include                <math.h>
#include		<stdlib.h>

#define align4(x)       (((((x) -1) >>2) <<2)+4)
#define TRUE            1
#define FALSE           0
#define MAX             64

typedef struct          s_virt
{
  int			free;
  size_t		size;
  struct  s_virt	*next;
  struct  s_virt	*prev;
  struct  s_virt	*f_next;
  char			start[1];
}                       t_virt;

typedef struct          s_info
{
  t_virt		*l_list;
  t_virt		*e_list;
  pthread_mutex_t	mu;
  void			*start;
  void			*end;
  int			pagesize;
  t_virt		*next;
  t_virt		*prev;
}                       t_info;

extern t_info           info;
extern size_t           exp_two[MAX];
extern t_virt           *table[MAX];

                        /* --- list.c --- */
t_virt                  *init_list(size_t);
t_virt                  *init_list_cpy(size_t, t_virt *);
void                    delete_list(t_virt *);

                        /* --- list2.c --- */
t_virt                  *last_elem(t_virt*);
t_virt                  *found_ptr(void*);
t_virt                  *extend_size(t_virt*, size_t);
void                    delete_list_free(t_virt*);
void                    init_new_list(t_virt*, size_t);

                        /* --- list3.c --- */
t_virt                  *fusion(t_virt *);

                        /* --- malloc.c --- */
void                    *malloc(size_t);

                        /* --- free.c --- */
void                    free(void *);

                        /* --- realloc.c --- */
void                    *realloc(void *, size_t);
t_virt                  *sub_realloc_last_elem(t_virt *, size_t);
t_virt                  *sub_realloc_elem(t_virt *, size_t);

                        /* --- calloc.c --- */
void                    *calloc(size_t, size_t);

                        /* --- info.c --- */
void                    init_info();
void                    update_info();

                        /* --- math.c --- */
t_virt*                 size_alloc(size_t);
size_t                  math_pow(size_t, size_t);
int                     know_sizeof_block(size_t);

                        /* --- debug.c --- */
void                    aff_t_virt(t_virt*);
void                    aff_table(int);
void                    aff_all_table();

                        /* --- table.c --- */
void                    init_table();
void                    add_to_table(int, t_virt *);
t_virt                  *take_to_table(int);
void                    auto_delete(t_virt *);
int                     bad_elem(t_virt *, int);

                        /* --- exp.c --- */
void                    init_exp();

#endif                  /* LIBMY_MALLOC_H_ */
