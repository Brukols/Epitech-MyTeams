##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## Makefile
##

NAME	= 	myteams_cli

SRCS	=	src/main.c 		\
			src/client.c	\
			src/help/help.c	\
			src/init/init_client.c	\
			src/init/connect_client.c	\
			src/clean/close_client.c	\
			src/process/run_client.c	\
			src/process/select_activities.c	\
			src/process/handle_io_activities.c	\
			src/process/client/handle_client_activities.c	\
			src/user_message/user_add_to_message.c	\
			src/user_message/user_get_message.c	\
			src/user_message/user_is_waiting_message.c	\
			src/user_message/user_new_message.c	\
			src/user_message/user_receive_message.c	\
			src/user_message/user_send_message.c	\

CFLAGS += 	-W -Wall -Wextra -Wshadow -Werror -Iinclude/

LDFLAGS +=  \

OBJS	=	$(SRCS:.c=.o)

OBJS_TESTS =	$(SRCS:.c=.gcda) $(SRCS:.c=.gcno)

CC	=	gcc

RM		=	rm -f

MV	=	mv

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	$(MV) $(NAME) ../

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../$(NAME)

tests_run: LDFLAGS += -lgcov --coverage
tests_run: CFLAGS += -fprofile-arcs -ftest-coverage
tests_run: re
			./tests/tests.sh

debug: CFLAGS += -g
debug: re

re: fclean all

.PHONY: all clean fclean re tests_run debug
