/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** TODO: add description
*/

#include "my_array.h"

static int check_alphanumeric(char c, char sep)
{
    if (c != sep && c != '\n' && c != '\0' && c != '\t' && c != '\r') {
        return 1;
    } else {
        return 0;
    }
}

static int count_word(char *str, char sep)
{
    int word_number = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (check_alphanumeric(str[i], sep)
        && !check_alphanumeric(str[i + 1], sep)) {
            word_number++;
        }
    }
    return word_number;
}

char **my_strtok(char *str, char sep)
{
    int index = 0;
    int len_word = 0;
    char **tab_result = calloc((count_word(str, sep) + 1), sizeof(char *));
    if (tab_result == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++) {
        if (check_alphanumeric(str[i], sep))
            len_word++;
        if (check_alphanumeric(str[i], sep)
        && !check_alphanumeric(str[i + 1], sep)) {
            tab_result[index] = calloc(len_word + 1, sizeof(char));
            if (tab_result[index] == NULL)
                return NULL;
            strncpy(tab_result[index], &str[i - len_word + 1], len_word);
            len_word = 0;
            index++;
        }
    }
    tab_result[index] = NULL;
    return tab_result;
}