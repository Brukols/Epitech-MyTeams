/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** TODO: add description
*/

#include "generic_list.h"

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position, void
(*del)(void* data))
{
    node_t *to_delete = NULL;
    node_t *temp = NULL;
    unsigned int i = 0;

    if (list_is_empty(*front_ptr)) return (false);
    if (list_get_size(*front_ptr) <= (position)) return (false);
    if (!position) return (list_del_elem_at_front(front_ptr, del));
    if ((position - 1) == list_get_size(*front_ptr))
        return (list_del_elem_at_back(front_ptr, del));

    for (to_delete = *front_ptr; i != position; to_delete = to_delete->next,
    i++) {
        if (!to_delete) return (false);
        temp = to_delete;
    }
    temp->next = to_delete->next;
    list_delete_node(to_delete, del);
    return (true);
}