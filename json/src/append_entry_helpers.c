/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json_parser.h"

int find_field(char *str, int *i, int *nb_of_entries)
{
    int indicator = 0;
    int marker = 0;

    if (check_marker(str, i, '{') == NOT_FOUND)
        return (NOT_FOUND);
    do {
        skip_white_spaces(str, i);
        if (str[*i] == '}')
            break;
        if (check_routine_key_value(str, i) != VALID_VALUE)
            return (SYNTAX_ERROR);
        (*nb_of_entries)++;
        indicator = check_marker(str, i, ',');
    } while (indicator == VALID_VALUE);
    marker = *i;
    if (check_marker(str, i, '}') == NOT_FOUND)
        return (SYNTAX_ERROR);
    *i = marker;
    return (VALID_VALUE);
}

int insert_first_entry(json_t newjson,
    json_t oldjson, json_t entry, int i)
{
    int i2 = 0;

    for (i2; i2 < i; i2++)
        newjson[i2] = oldjson[i2];
    for (int i3 = 0; entry[i3] != 0; i3++, i2++)
        newjson[i2] = entry[i3];
    for (i; oldjson[i - 1] != 0; i++, i2++)
        newjson[i2] = oldjson[i];
    return (0);
}

int insert_entry(json_t newjson,
    json_t oldjson, json_t entry, int i)
{
    int i2 = 0;

    for (i2; i2 < i; i2++)
        newjson[i2] = oldjson[i2];
    newjson[i2++] = ',';
    for (int i3 = 0; entry[i3] != 0; i3++, i2++)
        newjson[i2] = entry[i3];
    for (i; oldjson[i - 1] != 0; i++, i2++)
        newjson[i2] = oldjson[i];
    return (0);
}

int append_entry(json_t *json, json_t new_entry)
{
    int length = strlen(*json) + strlen(new_entry) + 1;
    json_t new_json = NULL;
    int i = 0;
    int nb_of_entries = 0;

    if (find_field(*json, &i, &nb_of_entries) == VALID_VALUE) {
        if (nb_of_entries > 0)
            length += 1;
        if ((new_json = malloc(sizeof(char) * length)) == NULL)
            return (JSON_APPEND_FAILED);
        if (nb_of_entries != 0)
            insert_entry(new_json, *json, new_entry, i);
        else
            insert_first_entry(new_json, *json, new_entry, i);
        free(new_entry);
        free(*json);
        *json = new_json;
        return (JSON_APPEND_SUCCEED);
    }
    free(new_entry);
    return (JSON_APPEND_FAILED);
}
