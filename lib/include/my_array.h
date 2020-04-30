/*
** EPITECH PROJECT, 2019
** my_teams
** File description:
** MY_ARRAY
*/

#ifndef MY_ARRAY_H_
#define MY_ARRAY_H_

/*
** Types
*/

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/*
** Functions
*/

char **my_strtok(char *str, char sep);
char **free_array(char **array);
int get_size_array(char **array);

#endif /* !MY_ARRAY_H_ */
