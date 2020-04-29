/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** TODO: add description
*/

#include "generic_list.h"

bool list_delete_node(node_t *node, void (*del)(void* data))
{
    if (!node) return (true);
    del(node->value);
    free(node);
    return (true);
}