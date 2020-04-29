/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** smart buffer
*/

#include "smart_buffer.h"

smart_buffer_t *smart_buffer_create(void)
{
    smart_buffer_t *ret = malloc(sizeof(smart_buffer_t));

    if (!ret)
        return (NULL);
    *ret = (smart_buffer_t){0};
    ret->buffer = calloc(sizeof(char) * INITIAL_SIZE, 1);
    if (!ret->buffer)
        return (NULL);
    ret->size = INITIAL_SIZE;
    return (ret);
}

void smart_buffer_destroy(smart_buffer_t *smart_buffer)
{
    free(smart_buffer->buffer);
    free(smart_buffer);
}

bool smart_buffer_add_string(smart_buffer_t *buffer, const char *str)
{
    
}

bool smart_buffer_add_data(smart_buffer_t *buff, const void *data, size_t size)
{
    
}
