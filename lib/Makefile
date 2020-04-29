##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A simple Makefile to compile my lib list
##

NAME	=	libutils.a

SRC	=	src/list_add_elem_at_back.c	\
		src/list_add_elem_at_front.c	\
		src/list_add_elem_at_position.c	\
		src/list_clear.c	\
		src/list_create_node.c	\
		src/list_del_elem_at_back.c	\
		src/list_del_elem_at_front.c	\
		src/list_del_elem_at_position.c	\
		src/list_del_elem_at_value.c	\
		src/list_delete_node.c	\
		src/list_dump.c	\
		src/list_get_elem_at_back.c	\
		src/list_get_elem_at_front.c	\
		src/list_get_elem_at_position.c	\
		src/list_get_first_node_with_value.c	\
		src/list_get_size.c	\
		src/list_is_empty.c	\
		src/smart_buffer.c	\

CFLAGS = 	-Iinclude -W -Wall -Wshadow -Wextra -Werror

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

tests_run:



.PHONY: all clean fclean re
