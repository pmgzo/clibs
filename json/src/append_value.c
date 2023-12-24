/*
** EPITECH PROJECT, 2020
** project
** File description:
** json
*/

#include "json_append.h"

int append_long_int(json_t *json, char *key, long value)
{
    char *new_entry = create_entry_number(key, value);

    if (new_entry == NULL) {
        return (JSON_APPEND_FAILED);
    }
    return (append_entry(json, new_entry));
}

int append_str(json_t *json, char *key, char *value)
{
    char *new_entry = create_entry_str(key, value);

    if (new_entry == NULL) {
        return (JSON_APPEND_FAILED);
    }
    return (append_entry(json, new_entry));
}

int append_obj(json_t *json, char *key, json_t obj)
{
    char *new_entry = create_entry(key, obj);

    if (new_entry == NULL) {
        return (JSON_APPEND_FAILED);
    }
    return (append_entry(json, new_entry));
}