/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** TODO: add description
*/

#include "generic_list.h"

bool list_del_elem_at_front(list_t *front_ptr, void (*del)(void* data))
{
    node_t *to_delete = *front_ptr;
    if (list_is_empty(*front_ptr)) return (false);

    *front_ptr = to_delete->next;
    if (del)
        del(to_delete->value);
    free(to_delete);
    return (true);
}