##
## EPITECH PROJECT, 2020
## libmyteams client
## File description:
## 
##

NAME	=	libmyteams.so
CC	=	gcc
CFLAGS	=	-fPIC -Wall -Wextra -Wshadow -O2 -I../
LDFLAGS	=	-shared
SRCS	=	logging_client.c logging_server.c
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
