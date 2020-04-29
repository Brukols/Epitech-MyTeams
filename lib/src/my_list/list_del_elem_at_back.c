/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** TODO: add description
*/

#include "generic_list.h"

bool list_del_elem_at_back(list_t *front_ptr, void (*del)(void* data))
{
    node_t *to_delete = NULL;
    if (list_is_empty(*front_ptr)) return (false);
    if (list_get_size(*front_ptr) == 1) {
        list_delete_node(*front_ptr, del);
        *front_ptr = NULL;
        return (true);
    }
    for (node_t *temp = *front_ptr; temp->next; temp = temp->next)
        to_delete = temp;
    list_delete_node(to_delete->next, del);
    to_delete->next = NULL;
    return (true);
}