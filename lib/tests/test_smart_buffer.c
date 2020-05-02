/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** smart buffer tests
*/

#include "smart_buffer.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(smart_buffer, basic_test)
{
    smart_buffer_t *buffer = smart_buffer_create();
    char *hello = "Hello!";
    char string[10] = {0};

    cr_assert(buffer);
    cr_expect(smart_buffer_get_size(buffer) == 0);
    cr_expect(smart_buffer_add_string(buffer, hello));
    cr_expect(smart_buffer_get_size(buffer) == strlen(hello));
    cr_expect(smart_buffer_get_data(buffer, string, strlen(hello)));
    cr_expect_str_eq(string, hello);
    cr_expect(smart_buffer_get_size(buffer) == 0);
    smart_buffer_destroy(buffer);
}

static bool fct(smart_buffer_t *buff, void *arg)
{
    (void)buff;
    (void)arg;
    return (false);
}

Test(smart_buffer, get_data_if)
{
    smart_buffer_t *buffer = smart_buffer_create();
    char *hello = "Hello!";
    char string[10] = {0};

    cr_assert(buffer);
    cr_expect(smart_buffer_get_size(buffer) == 0);
    cr_expect(smart_buffer_add_string(buffer, hello));
    cr_expect(smart_buffer_get_size(buffer) == strlen(hello));
    cr_expect(!smart_buffer_get_data_if(buffer, string, strlen(hello), fct));
    cr_expect_str_eq(string, hello);
    cr_expect(smart_buffer_get_size(buffer) == strlen(hello));
    smart_buffer_destroy(buffer);
}

Test(smart_buffer, write, .init = redirect_all_std)
{
    smart_buffer_t *buffer = smart_buffer_create();
    char *hello = "Hello!";

    cr_assert(buffer);
    cr_expect(smart_buffer_get_size(buffer) == 0);
    cr_expect(smart_buffer_add_string(buffer, hello));
    cr_expect(smart_buffer_get_size(buffer) == strlen(hello));
    cr_expect(smart_buffer_write(buffer, 1) == (ssize_t)strlen(hello));
    cr_expect_stdout_eq_str(hello);
    smart_buffer_destroy(buffer);
}

Test(smart_buffer, a_lot_of_data)
{
    smart_buffer_t *buffer = smart_buffer_create();
    char sent[10000] = {100};
    char received[10000] = {0};

    cr_assert(buffer);
    cr_expect(smart_buffer_get_size(buffer) == 0);
    cr_expect(smart_buffer_add_data(buffer, sent, sizeof(sent)));
    cr_expect(smart_buffer_get_size(buffer) == 10000);
    cr_expect(smart_buffer_get_data(buffer, received, sizeof(sent)));
    cr_expect(memcmp(sent, received, 10000) == 0);
    cr_expect(smart_buffer_get_size(buffer) == 0);
    smart_buffer_destroy(buffer);
}
