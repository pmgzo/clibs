/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json_parser.h"

char *get_string(int *i2, json_t json, int expected_type)
{
    int tmp = *i2;

    if (expected_type == STR
        && check_type(json, i2) == expected_type) {
        return (strndup(json + tmp + 1,  *i2 - tmp - 2));
    }
    else if (expected_type == OBJ
        && check_type(json, i2) == expected_type) {
        return (strndup(json + tmp,  *i2 - tmp));
    }
    return (NULL);
}

long get_long_int(int *i2, json_t json)
{
    int tmp = *i2;

    if (check_type(json, i2) == NUMBER)
        return (atol(json + tmp));
    return (-1);
}
