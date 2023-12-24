/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json.h"

long get_value_long_int(json_t json, char *key)
{
    int pos = find_json_key(json, key);

    if (pos == -1) {
        return (-1);
    }
    return get_long_int(&pos, json);
}

char *get_value_str(json_t json, char *key)
{
    int pos = find_json_key(json, key);

    if (pos == -1) {
        return (NULL);
    }
    return get_string(&pos, json, STR);
}

json_t get_value_obj(json_t json, char *key)
{
    int pos = find_json_key(json, key);

    if (pos == -1) {
        return (NULL);
    }
    return get_string(&pos, json, OBJ);
}
