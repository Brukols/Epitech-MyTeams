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
bool save_threads(list_t threads, const char *dir);
bool save_channels(list_t channels, const char *dir);
bool save_users(list_t users);

bool save_single_item(
    void *item, const char *dir,
    bool (*save_meta)(void *, int),
    bool (*save_data)(void *, int));

void load_team_subscriptions(list_t users, team_t *new_team, char *path);
team_t *load_team_metadata(char *path);
team_t *load_team_data(list_t users, char *path_team);

channel_t *load_channel_data(char *path);
void load_channel(list_t users, team_t *new_team, char *path, char *name_chan);

void load_thread(list_t users, channel_t *channel, char *path, char *thread_name);

#endif /* !SERVER_SAVING_UTILS_H_ */
