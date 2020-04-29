/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** smart buffer
*/

#include "smart_buffer.h"

bool smart_buffer_add_string(smart_buffer_t *buffer, const char *str)
{
    return (smart_buffer_add_data(buffer, str, strlen(str)));
}

bool smart_buffer_add_data(smart_buffer_t *buff, const void *data, size_t size)
{
    if (smart_buffer_get_size(buff) + size > SMART_BUFFER_SIZE)
        return (false);
    for (size_t i = 0; i < size; i++) {
        buff->buffer[buff->end] = (const char *){data}[i];
        buff->end++;
        if (buff->end == SMART_BUFFER_SIZE)
            buff->end = 0;
    }
    return (true);
}

bool smart_buffer_get_data_if(
    smart_buffer_t *buff, void *var, size_t size,
    bool (*fct)(smart_buffer_t *, void *))
{
    size_t pos = buff->start;

    if (size > smart_buffer_get_size(buff))
        return (false);
    for (size_t i = 0; i < size; i++) {
        (char *){var}[i] = buff->buffer[pos];
        pos++;
        if (pos == SMART_BUFFER_SIZE)
            pos = 0;
    }
    if (!fct(buff, var))
        return (false);
    buff->start += size;
    if (buff->start >= SMART_BUFFER_SIZE)
        buff->start -= SMART_BUFFER_SIZE;
    return (true);
}

bool smart_buffer_get_data(smart_buffer_t *buff, void *var, size_t size)
{
    if (size > smart_buffer_get_size(buff))
        return (false);
    for (size_t i = 0; i < size; i++) {
        (char *){var}[i] = buff->buffer[buff->start];
        buff->start++;
        if (buff->start == SMART_BUFFER_SIZE)
            buff->start = 0;
    }
    return (true);
}
