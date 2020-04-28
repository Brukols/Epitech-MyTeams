##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## Makefile
##

NAME	= 	myteams_server

SRCS	=	src/main.c		\
			src/my_teams.c	\
			src/help/help.c	\
			src/server/init_server.c	\
			src/server/launch_server.c		\
			src/signal/sig_handler.c		\
			src/signal/terminate.c			\

CFLAGS += 	-W -Wall -Wextra -Wshadow -I include/ -I ../lib/my_list/include

LDFLAGS +=  -l my_list -L ./../lib/ \

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
