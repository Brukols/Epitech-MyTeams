/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** smart buffer
*/

#include "smart_buffer.h"
#include <stdio.h>

static bool smart_buffer_realloc(smart_buffer_t *buff, size_t new_size)
{
    buff->buffer = realloc(buff->buffer, new_size);
    if (!buff->buffer)
        return (false);
    buff->size = new_size;
    return (true);
}

bool smart_buffer_add_string(smart_buffer_t *buffer, const char *str)
{
    return (smart_buffer_add_data(buffer, str, strlen(str)));
}

bool smart_buffer_add_data(smart_buffer_t *buff, const void *data, size_t size)
{
    if (smart_buffer_get_size(buff) + size > buff->size)
        if (!smart_buffer_realloc(buff, smart_buffer_get_size(buff) + size))
            return (false);
    memcpy(buff->buffer + buff->end, data, size);
    buff->end += size;
    return (true);
}

bool smart_buffer_get_data_if(smart_buffer_t *buff, void *var, size_t size,
bool (*fct)(smart_buffer_t *, void *))
{
    if (size > smart_buffer_get_size(buff))
        return (false);
    memcpy(var, buff->buffer, size);
    if (fct && !fct(buff, var))
        return (false);
    buff->end -= size;
    buff->buffer = memmove(buff->buffer, buff->buffer + size, buff->end);
    return (true);
}

bool smart_buffer_get_data(smart_buffer_t *buff, void *var, size_t size)
{
    return (smart_buffer_get_data_if(buff, var, size, NULL));
}
