##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## Makefile
##

all:
	make -C lib/
	make -C server/
	make -C client/

clean:
	make clean -C lib/
	make clean -C server/
	make clean -C client/

fclean:
	make fclean -C lib/
	make fclean -C server/
	make fclean -C client/

tests_run:
	make tests_run -C server/
	make tests_run -C client/
	make tests_run -C lib/

debug:
	make debug -C server/
	make debug -C client/
	make debug -C lib/

lib:
	make -C lib/

re:
	make re -C lib/
	make re -C server/
	make re -C client/

.PHONY: all clean fclean re tests_run debug lib
