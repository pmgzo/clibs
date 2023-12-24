/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json_append.h"

int append_long_int_array(json_t *json, char *key, long *array)
{
    char *new_entry = create_array_int_entry(key, array);

    if (new_entry == NULL) {
        return (JSON_APPEND_FAILED);
    }
    return (append_entry(json, new_entry));
}

int append_str_array(json_t *json, char *key, char **array)
{
    char *new_entry = create_array_str_entry(key, array);

    if (new_entry == NULL) {
        return (JSON_APPEND_FAILED);
    }
    return (append_entry(json, new_entry));
}

int append_obj_array(json_t *json, char *key, json_t *obj_array)
{
    char *new_entry = create_array_obj_entry(key, obj_array);

    if (new_entry == NULL) {
        return (JSON_APPEND_FAILED);
    }
    return (append_entry(json, new_entry));
}
