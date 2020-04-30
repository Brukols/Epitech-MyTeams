/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** TODO: add description
*/

#include "my_array.h"

char **free_array(char **array)
{
    if (array != NULL) {
        for (int i = 0; array[i] != NULL; i++)
            free(array[i]);
        free(array);
    }
    return (NULL);
}