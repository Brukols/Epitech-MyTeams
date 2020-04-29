/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** TODO: add description
*/

#include "generic_list.h"

void list_clear(list_t *front, void (*del)(void* data))
{
    node_t *to_delete = NULL;

    while (*front) {
        to_delete = *front;
        *front = (*front)->next;
        list_delete_node(to_delete, del);
    }
    front = NULL;
}