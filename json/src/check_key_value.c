/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json_parser.h"

int check_key(char *str, int *i)
{
    int rt = string_checker(str, i);

    if (rt == VALID_VALUE) {
        rt = check_marker(str, i, ':');
        if (rt == NOT_FOUND)
            return (SYNTAX_ERROR);
    }
    return (rt);
}

int check_value(char *str, int *i)
{
    int rt = 0;
    int tmp = *i;

    for (int idx = 0; idx < 4; idx++) {
        tmp = *i;
        rt = array_value_checker[idx](str, &tmp);
        if (rt == SYNTAX_ERROR || rt == VALID_VALUE) {
            *i = tmp;
            return (rt);
        }
    }
    return (NOT_FOUND);
}

int check_routine_key_value(char *str, int *i)
{
    int rt = check_key(str, i);

    if (rt == VALID_VALUE) {
        skip_white_spaces(str, i);
        rt = check_value(str, i);
    }
    return (rt);
}
