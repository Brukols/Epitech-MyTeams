/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** TODO: add description
*/

#include "generic_list.h"

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    node_t *temp = NULL;
    unsigned int i = 0;

    if (list_is_empty(list)) return (0);
    if (!position) return (list_get_elem_at_front(list));
    if (list_get_size(list) <= (position)) return (0);

    for (temp = list->next, i = 1; i != position; temp = temp->next, i++);
    return (temp->value);
}