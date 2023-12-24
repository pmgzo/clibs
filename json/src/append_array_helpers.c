/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json_append.h"

json_t build_json_long_int_array(long *array)
{
    char *tmp;
    char *data = strdup("[");
    char *new_value;

    for (int i = 0; array[i] != 0xDEAD; i++) {
        if (array[i + 1] != 0xDEAD)
            asprintf(&new_value, "%ld,", array[i]);
        else
            asprintf(&new_value, "%ld]", array[i]);
        if (new_value == NULL)
            return (NULL);
        tmp = str_append(data, new_value);
        if (tmp == NULL)
            return (NULL);
        free(data);
        free(new_value);
        data = tmp;
    }
    return (data);
}

json_t build_json_str_array(char **array)
{
    char *tmp;
    char *data = strdup("[");
    char *new_value;

    for (int i = 0; array[i] != NULL; i++) {
        if (array[i + 1] != NULL)
            asprintf(&new_value, "\"%s\",", array[i]);
        else
            asprintf(&new_value, "\"%s\"]", array[i]);
        if (new_value == NULL)
            return (NULL);
        tmp = str_append(data, new_value);
        if (tmp == NULL)
            return (NULL);
        free(data);
        free(new_value);
        data = tmp;
    }
    return (data);
}

json_t build_json_obj_array(char **array)
{
    char *tmp;
    char *data = strdup("[");
    char *new_value;

    for (int i = 0; array[i] != NULL; i++) {
        if (array[i + 1] != NULL)
            asprintf(&new_value, "%s,", array[i]);
        else
            asprintf(&new_value, "%s]", array[i]);
        if (new_value == NULL)
            return (NULL);
        tmp = str_append(data, new_value);
        if (tmp == NULL)
            return (NULL);
        free(data);
        free(new_value);
        data = tmp;
    }
    return (data);
}
