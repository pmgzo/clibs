/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json.h"

int get_key_type(json_t json, char *key)
{
    int pos = find_json_key(json, key);

    return (check_type(json, &pos));
}
