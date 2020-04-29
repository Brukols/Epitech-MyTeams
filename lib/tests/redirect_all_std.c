/*
** EPITECH PROJECT, 2020
** redirect all std
** File description:
** check stdout
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
