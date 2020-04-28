/*
** EPITECH PROJECT, 2020
** my_ftp
** File description:
** TODO: add description
*/

#include "generic_list.h"

void list_dump(list_t list, value_displayer_t val_disp)
{
    for (node_t *temp = list; temp; temp = temp->next)
        val_disp(temp->value);
}