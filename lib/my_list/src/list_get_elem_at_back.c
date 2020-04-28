/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** TODO: add description
*/

#include "generic_list.h"

void *list_get_elem_at_back(list_t list)
{
    node_t *temp = NULL;

    if (list_is_empty(list)) return (0);
    for (temp = list; temp->next; temp = temp->next);
    return (temp->value);
}