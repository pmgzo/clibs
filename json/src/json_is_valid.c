/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json_parser.h"

int check_json(json_t json)
{
    int i = 0;

    if (object_checker(json, &i) != VALID_VALUE)
        return (INVALID_JSON);
    return (VALID_JSON);
}

int json_is_valid(json_t json)
{
    if (json == NULL) {
        return (INVALID_JSON);
    }
    return check_json(json);
}
