/*
** show_alloc_mem.c for malloc in /home/nurenb_c/Rendu/PSU_2015_malloc
**
** Made by Nurenberg corentin
** Login   <nurenb_c@epitech.net>
**
** Started on  Thu Feb 11 13:20:16 2016 Nurenberg corentin
** Last update Sun Feb 14 11:24:32 2016 Julien Karst
*/

void		show_alloc_mem()
{
  printf("************MALLOC************\n");
  printf("break : %p\n", sbrk(0));
  while (var != NULL)
    {
      if (var->free == FALSE)
	printf("%p - %p : %d Octets \n",
	       var->start, var + var->size, var->size);
      else
	printf("Free %p - %p : %d Octets \n",
	       var->start, var + var->size, var->size);
      var = var->next;
    }
  printf("******************************\n");
}
