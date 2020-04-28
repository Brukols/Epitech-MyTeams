##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## Makefile
##

all:
	make -C lib/my_list/
	make -C server/
	make -C client/

clean:
	make clean -C lib/my_list/
	make clean -C server/
	make clean -C client/

fclean:
	make fclean -C lib/my_list/
	make fclean -C server/
	make fclean -C client/

tests_run:
	make tests_run -C server/
	make tests_run -C client/

debug:
	make debug -C server/
	make debug -C client/

lib:
	make -C lib/my_list/

re:
	make re -C lib/my_list/
	make re -C server/
	make re -C client/

.PHONY: all clean fclean re tests_run debug lib
