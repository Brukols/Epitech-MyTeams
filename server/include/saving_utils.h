/*
** EPITECH PROJECT, 2020
** saving utils
** File description:
** functions used by save_server
*/

#ifndef SERVER_SAVING_UTILS_H_
#define SERVER_SAVING_UTILS_H_

#include "saving.h"
#include "file_types.h"

bool write_buffer(int fd, const char *buffer, size_t size);

bool prepare_saving_directory(void);
bool check_and_create_directory(const char *dir);

int get_meta_fd(const char *dir);
int get_data_fd(const char *dir);

bool save_teams(list_t teams);
bool save_threads(list_t teams);
bool save_channels(list_t teams);
bool save_users(list_t users);

#endif /* !SERVER_SAVING_UTILS_H_ */
