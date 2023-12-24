/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json_parser.h"

int check_marker(char *str, int *i, char token)
{
    skip_white_spaces(str, i);
    if (str[*i] == token) {
        (*i)++;
        return (VALID_VALUE);
    }
    else
        return (NOT_FOUND);
}
