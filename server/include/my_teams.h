/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#ifndef NWP_MYTEAMS_2019_MY_TEAMS_H
#define NWP_MYTEAMS_2019_MY_TEAMS_H

/**************************************
** INCLUDE
**************************************/

/**************************************
** DEFINE
**************************************/
#define TEAMS_ERROR 84
#define TEAMS_SUCCESS 0

/**************************************
** STRUCT
**************************************/

/**************************************
** FUNCTION
**************************************/
int my_teams(int ac, char **av);

/* HELP */
int display_help();
int teams_verif_arg(int ac, char **av);

#endif //NWP_MYTEAMS_2019_MY_TEAMS_H
