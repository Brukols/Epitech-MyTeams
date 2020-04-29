/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** TODO: add description
*/

#include "generic_list.h"

bool list_del_elem_at_value(list_t *front_ptr, void *value, void
(*del)(void* data))
{
    node_t *to_delete = NULL;
    node_t *temp = NULL;

    if (list_is_empty(*front_ptr)) return (false);
    if ((*front_ptr)->value == value) return (list_del_elem_at_front(front_ptr,
        del));

    for (to_delete = *front_ptr; to_delete; to_delete = to_delete->next) {
        if (to_delete->next->value == value)
            break;
    }
    if (!to_delete)
        return false;
    if (to_delete->next->next == NULL)
        return (list_del_elem_at_back(front_ptr, del));
    temp = to_delete->next;
    to_delete->next = temp->next;
    list_delete_node(temp, del);
    return (true);
}