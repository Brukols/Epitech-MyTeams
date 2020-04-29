/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** smart buffer
*/

#ifndef SMART_BUFFER_H
#define SMART_BUFFER_H

#define INITIAL_SIZE 1024

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct smart_buffer {
    char *buffer;
    size_t size;
    size_t end;
} smart_buffer_t;

smart_buffer_t *smart_buffer_create(void);
void smart_buffer_destroy(smart_buffer_t *smart_buffer);

bool smart_buffer_add_string(smart_buffer_t *buffer, const char *str);
bool smart_buffer_add_data(smart_buffer_t *buff, const void *data, size_t size);

bool smart_buffer_get_data(smart_buffer_t *buffer, void *var, size_t size);

void smart_buffer_empty(smart_buffer_t *buff);


#endif /* !SMART_BUFFER_H */
