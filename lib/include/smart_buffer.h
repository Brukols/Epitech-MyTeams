/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** smart buffer
*/

#ifndef SMART_BUFFER_H
#define SMART_BUFFER_H

#define SMART_BUFFER_SIZE 16384
#define SMART_BUFFER_MAX_WRITE 512

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct smart_buffer {
    char buffer[SMART_BUFFER_SIZE];
    size_t start;
    size_t end;
} smart_buffer_t;

smart_buffer_t *smart_buffer_create(void);
void smart_buffer_destroy(smart_buffer_t *smart_buffer);

bool smart_buffer_add_string(smart_buffer_t *buffer, const char *str);
bool smart_buffer_add_data(smart_buffer_t *buff, const void *data, size_t size);

bool smart_buffer_get_data(smart_buffer_t *buffer, void *var, size_t size);
bool smart_buffer_get_data_if(
    smart_buffer_t *buffer, void *var, size_t size,
    bool (*fct)(smart_buffer_t *, void *));

size_t smart_buffer_get_size(const smart_buffer_t *buffer);
void smart_buffer_empty(smart_buffer_t *buff);

ssize_t smart_buffer_read(smart_buffer_t *buffer, int fd);
ssize_t smart_buffer_write(smart_buffer_t *buffer, int fd);

#endif /* !SMART_BUFFER_H */
