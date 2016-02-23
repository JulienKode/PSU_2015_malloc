/*
** math.c for  in /home/karst_j/PSU_2015_malloc/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Jan 28 09:52:29 2016 Julien Karst
** Last update Sun Feb 14 11:11:22 2016 Julien Karst
*/

#include	"libmy_malloc.h"

int		bonus()
{
  int		c;
  int		i;
  int		result;
  FILE		*fp;

  i = 0;
  result = 0;
  fp = fopen("/etc/malloc.conf", "r");
  while ((c = fgetc(fp)) != 0);
  {
    if ( feof(fp) )
      return (result);
    if (c >= '0' && c <= '9' && i < 2)
      result = (result*10) + (c - '0');
    else
      return (-1);
    i++;
  }
  fclose(fp);
  return (0);
}
