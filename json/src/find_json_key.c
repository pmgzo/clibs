/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json_parser.h"

int find_key_in_entry(char *str, int *i, char *searching_key, int *pos)
{
    int tmp = *i;
    int rt = check_key(str, i);
    int res = strncmp(str + tmp, searching_key, strlen(searching_key));

    if (rt == VALID_VALUE) {
        skip_white_spaces(str, i);
        tmp = *i;
        rt = check_value(str, i);
        if (res == 0 && *pos == -1)
            *pos = tmp;
    }
    return (rt);
}

int browse_object(char *str, int *i, char *searching_key)
{
    int indicator = 0;
    int pos = -1;

    if (check_marker(str, i, '{') == NOT_FOUND)
        return (-1);
    do {
        skip_white_spaces(str, i);
        if (find_key_in_entry(str, i, searching_key, &pos) != VALID_VALUE)
            return (-1);
        if (pos != -1)
            return (pos);
        indicator = check_marker(str, i, ',');
    } while (indicator == VALID_VALUE);
    if (check_marker(str, i, '}') == NOT_FOUND)
        return (-1);
    return (-1);
}

int find_json_key(json_t json, char *key)
{
    int i = 0;
    char *formatized_key = NULL;
    int pos = 0;

    asprintf(&formatized_key, "\"%s\"", key);
    if (formatized_key == NULL)
        return (-1);
    pos = browse_object(json, &i, formatized_key);
    free(formatized_key);
    return (pos);
}
