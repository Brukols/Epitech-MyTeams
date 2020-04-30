##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## Makefile
##

NAME	= 	myteams_server

LIB_NAME	=	utils

SRCS	=	src/main.c		\
			src/my_teams.c	\
			src/help/help.c	\
			src/server/init_server.c	\
			src/server/launch_server.c		\
			src/server/translate_select.c	\
			src/server/new_connection.c		\
			src/server/read_data_client.c	\
			src/server/write_data_client.c	\
			src/server/delete_server.c		\
			src/server/translate_data_client.c		\
			src/signal/sig_handler.c		\
			src/signal/terminate.c			\
			src/client/create_client.c		\
			src/client/delete_client.c		\
			src/buffer/concat_buffer.c		\
			src/buffer/erase_buffer.c		\
			src/utils/send_response.c		\
			src/user/create_user.c			\
			src/server/commands/help/command_help.c	\
			src/server/commands/login/command_login.c	\
			src/server/commands/logout/command_logout.c	\

CFLAGS += 	-W -Wall -Wextra -Wshadow -I include/ -I ../lib/include -I ../include

LDFLAGS +=  -l $(LIB_NAME) -L ./../lib/ -luuid

OBJS	=	$(SRCS:.c=.o)

OBJS_TESTS =	$(SRCS:.c=.gcda) $(SRCS:.c=.gcno)

CC	=	gcc

RM		=	rm -f

MV 	=	mv

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	$(MV) $(NAME) ../

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_TESTS)

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
