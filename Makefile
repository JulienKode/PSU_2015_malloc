##
## Makefile for  in /home/karst_j/PSU_2015_malloc
##
## Made by Julien Karst
## Login   <karst_j@epitech.net>
##
## Started on  Thu Jan 28 09:56:08 2016 Julien Karst
## Last update Tue Feb 23 21:09:44 2016 Julien Karst
##

$(info ************  Malloc ************)

NAME1	= libmy_malloc_$(HOSTTYPE).so

NAME2	= libmy_malloc.so

SRCS	= 	sources/malloc.c 	\
			sources/free.c		\
			sources/calloc.c	\
			sources/realloc.c	\
			sources/list.c 		\
			sources/list2.c 	\
			sources/list3.c		\
			sources/info.c		\
			sources/table.c		\
			sources/exp.c		\
			sources/debug.c		\
			sources/math.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

CC	= gcc

CFLAGS	= -W -Wall -Wextra -Werror -g -I ./includes/

all:		$(NAME1)

$(NAME1):	$(OBJS)
		$(CC) -lpthread -lm -I ./includes/ -shared -fpic $(SRCS) -o $(NAME1)
		ln -fs $(NAME1) $(NAME2)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME1) $(NAME2)

re:		fclean all

test:
	$(info ************  Test ************)
	docker build -t malloctest .
	$(info test mouli	to test with moul_malloc_stud)
	$(info test htop	to test with htop)
	$(info test xterm	to test with xterm)
	$(info test ls		to test with ls -lRa /)

htop:
	$(info ************  htop test ************)
	docker run -ti --rm malloctest sh -c 'LD_PRELOAD=`pwd`/libmy_malloc.so htop'; echo "End"

xterm:
	$(info ************  xterm test ************)
	docker run -ti --rm -e DISPLAY=:1 -v /tmp/.X11-unix:/tmp/.X11-unix malloctest sh -c 'LD_PRELOAD=`pwd`/libmy_malloc.so xterm'; echo "End"

ls:
	docker run -ti --rm malloctest sh -c 'LD_PRELOAD=`pwd`/libmy_malloc.so ls -lRa /'; echo "End"

.PHONY:		all clean fclean re test
