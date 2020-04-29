/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** generic list test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "generic_list.h"

Test(generic_list, test)
{
    list_t list_head = NULL;
    int i = 5;
    int j = 42;
    int k = 3;

    list_add_elem_at_front(&list_head, &i);
    list_add_elem_at_back(&list_head, &j);
    list_add_elem_at_back(&list_head, &k);
    cr_assert(list_get_size(list_head) == 3);
    cr_assert(*(int *)list_head->value == 5);
    cr_assert(*(int *)list_head->next->value == 42);
    cr_assert(*(int *)list_head->next->next->value == 3);
    cr_assert(list_get_elem_at_position(list_head, 1) == &j);
    list_del_elem_at_back(&list_head);
    cr_assert(list_get_size(list_head) == 2);
    cr_assert(*(int *)list_head->value == 5);
    cr_assert(*(int *)list_head->next->value == 42);
    cr_assert(list_get_elem_at_front(list_head) == &i);
    cr_assert(list_get_elem_at_back(list_head) == &j);
    list_clear(&list_head);
    cr_assert(!list_head);
}

Test(generic_list, test2)
{
    list_t list_head = NULL;
    int i = 5;
    int j = 42;
    int k = 3;

    list_add_elem_at_front(&list_head, &i);
    list_add_elem_at_back(&list_head, &j);
    list_add_elem_at_back(&list_head, &k);
    cr_assert(list_get_size(list_head) == 3);
    cr_assert(*(int *)list_head->value == 5);
    cr_assert(*(int *)list_head->next->value == 42);
    cr_assert(*(int *)list_head->next->next->value == 3);
    cr_assert(list_get_elem_at_position(list_head, 1) == &j);
    list_del_elem_at_front(&list_head);
    cr_assert(list_get_size(list_head) == 2);
    cr_assert(*(int *)list_head->value == 42);
    cr_assert(*(int *)list_head->next->value == 3);
    cr_assert(list_get_elem_at_front(list_head) == &j);
    cr_assert(list_get_elem_at_back(list_head) == &k);
    list_clear(&list_head);
    cr_assert(!list_head && !list_get_size(list_head));
}

Test(generic_list, test3)
{
    list_t list_head = NULL;
    int i = 5;
    int j = 42;
    int k = 3;

    list_add_elem_at_front(&list_head, &i);
    list_add_elem_at_back(&list_head, &j);
    list_add_elem_at_back(&list_head, &k);
    cr_assert(list_get_size(list_head) == 3);
    cr_assert(*(int *)list_head->value == 5);
    cr_assert(*(int *)list_head->next->value == 42);
    cr_assert(*(int *)list_head->next->next->value == 3);
    cr_assert(list_get_elem_at_position(list_head, 1) == &j);
    list_del_node(&list_head, list_head->next->next);
    cr_assert(list_get_size(list_head) == 2);
    cr_assert(*(int *)list_head->value == 5);
    cr_assert(*(int *)list_head->next->value == 42);
    cr_assert(list_get_elem_at_front(list_head) == &i);
    cr_assert(list_get_elem_at_back(list_head) == &j);
    list_clear(&list_head);
    cr_assert(!list_head);
}
