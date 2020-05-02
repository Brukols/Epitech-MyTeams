##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## Makefile
##

NAME	= 	myteams_cli

LIB_NAME	=	utils

SRCS	=	src/main.c	\
			src/client.c	\
			src/help/help.c	\
			src/init/init_client.c	\
			src/init/connect_client.c	\
			src/clean/close_client.c	\
			src/process/run_client.c	\
			src/process/select_activities.c	\
			src/process/handle_io_activities.c	\
			src/process/client/handle_client_activities.c	\
			src/process/client/get_arg.c	\
			src/process/client/commands/create_cmd.c	\
			src/process/client/commands/help_cmd.c	\
			src/process/client/commands/info_cmd.c	\
			src/process/client/commands/list_cmd.c	\
			src/process/client/commands/login_cmd.c	\
			src/process/client/commands/logout_cmd.c	\
			src/process/client/commands/messages_cmd.c	\
			src/process/client/commands/send_cmd.c	\
			src/process/client/commands/subscribe_cmd.c	\
			src/process/client/commands/subscribed_cmd.c	\
			src/process/client/commands/unsubscribe_cmd.c	\
			src/process/client/commands/use_cmd.c	\
			src/process/client/commands/user_cmd.c	\
			src/process/client/commands/users_cmd.c	\
			src/process/server/handle_server_activities.c	\
			src/process/server/replies/reply_200.c	\
			src/process/server/replies/reply_201.c	\
			src/process/server/replies/reply_202.c	\
			src/process/server/replies/reply_210.c	\
			src/process/server/replies/reply_211.c	\
			src/process/server/replies/reply_212.c	\
			src/process/server/replies/reply_220.c	\
			src/process/server/replies/reply_230.c	\
			src/process/server/replies/reply_231.c	\
			src/process/server/replies/reply_232.c	\
			src/process/server/replies/reply_233.c	\
			src/process/server/replies/reply_330.c	\
			src/process/server/replies/reply_331.c	\
			src/process/server/replies/reply_501.c	\
			src/user_message/user_add_to_message.c	\
			src/user_message/user_get_message.c	\
			src/user_message/user_is_waiting_message.c	\
			src/user_message/user_new_message.c	\
			src/user_message/user_receive_message.c	\
			src/user_message/user_send_message.c	\

CFLAGS += 	-W -Wall -Wextra -Wshadow -I include/ -I ../lib/include -I ../include

LDFLAGS +=  -l $(LIB_NAME) -L ./../lib/ -luuid -Wl,-rpath=./ -lmyteams -L ./../

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
