/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json_append.h"

json_t create_array_int_entry(char *key, long *array)
{
    char *value = build_json_long_int_array(array);
    char *entry;

    if (value == NULL)
        return (NULL);
    entry = create_entry(key, value);
    free(value);
    return (entry);
}

json_t create_array_str_entry(char *key, char **array)
{
    char *value = build_json_str_array(array);
    char *entry;

    if (value == NULL)
        return (NULL);
    entry = create_entry(key, value);
    free(value);
    return (entry);
}

json_t create_array_obj_entry(char *key, char **array)
{
    char *value = build_json_obj_array(array);
    char *entry;

    if (value == NULL)
        return (NULL);
    entry = create_entry(key, value);
    free(value);
    return (entry);
}
