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
    ret->buffer = malloc(SMART_BUFFER_ORIGINAL_SIZE * sizeof(char));
    if (!ret->buffer) {
        free(ret);
        return (NULL);
    }
    ret->size = SMART_BUFFER_ORIGINAL_SIZE;
    ret->end = 0;
    return (ret);
}

void smart_buffer_destroy(smart_buffer_t *smart_buffer)
{
    free(smart_buffer->buffer);
    free(smart_buffer);
}

size_t smart_buffer_get_size(const smart_buffer_t *buffer)
{
    return (buffer->end);
}
