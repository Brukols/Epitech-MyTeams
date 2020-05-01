/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "myteams_client.h"
#include "my_array.h"
#include "myteams_commands.h"

int handle_client_activities(client_t *info)
{
    char *command = NULL;
    char **cmd_tab = NULL;
    int ret = CLIENT_ERROR;
    if ((command = user_getline_receive(info->user_out)) == NULL)
        return (CLIENT_SUCCESS);
    if ((cmd_tab = my_strtok(command, ' ')) == NULL) {
        free(command);
        return (CLIENT_ERROR);
    }
    for (int i = 0; commands[i].name != NULL && cmd_tab[0]; i++) {
        if (strcmp(cmd_tab[0], commands[i].name) == 0) {
            ret = commands[i].ft(info, command);
            break;
        }
    }
    if (ret == CLIENT_ERROR && cmd_tab[0])
        fprintf(stdout, "invalid command: %s", command);
    free_array(cmd_tab);
    free(command);
    return (CLIENT_SUCCESS);
}