/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** TODO: add description
*/

#include "generic_list.h"

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *new = list_create_node(elem);

    if (!new)
        return (false);
    new->next = *front_ptr;
    *front_ptr = new;

    return (true);
}