##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A simple Makefile to compile my lib list
##

TEST_NAME	=	unit_tests

NAME	=	libutils.a

SRC	=\
		src/my_list/list_dump.c	\
		src/my_list/list_clear.c	\
		src/my_list/list_add_elem_at_position.c	\
		src/my_list/list_del_elem_at_position.c	\
		src/my_list/list_add_elem_at_front.c	\
		src/my_list/list_del_elem_at_front.c	\
		src/my_list/list_del_elem_at_value.c	\
		src/my_list/list_delete_node.c	\
		src/my_list/list_get_elem_at_front.c	\
		src/my_list/list_get_size.c	\
		src/my_list/list_get_first_node_with_value.c	\
		src/my_list/list_add_elem_at_back.c	\
		src/my_list/list_is_empty.c	\
		src/my_list/list_del_elem_at_back.c	\
		src/my_list/list_get_elem_at_position.c	\
		src/my_list/list_create_node.c	\
		src/my_list/list_get_elem_at_back.c	\
		src/smart_buffer/smart_buffer_data.c	\
	    src/smart_buffer/smart_buffer_read_write.c	\
	    src/smart_buffer/smart_buffer_utils.c	\


TEST_SRC	=	\
				tests/redirect_all_std.c	\
				tests/test_generic_list.c	\
				tests/test_smart_buffer.c	\

CFLAGS = 	-Iinclude -W -Wall -Wshadow -Wextra -Werror

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ) *.gc*

fclean: clean
		$(RM) $(NAME) $(TEST_NAME)

re: fclean all

tests_run:	clean
			$(CC) -o $(TEST_NAME) $(CFLAGS) $(SRC) $(TEST_SRC) -lcriterion --coverage
			./$(TEST_NAME)
			gcovr -etests

.PHONY: all clean fclean re
