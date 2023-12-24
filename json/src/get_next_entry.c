/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json_parser.h"

int get_next_ent_idx(json_t json, int *nb_of_entries)
{
    int i = 0;
    int marker = 0;

    if (check_marker(json, &i, '[') == NOT_FOUND)
        return (-1);
    do {
        skip_white_spaces(json, &i);
        if (*nb_of_entries == 0 && json[i] == ']')
            return (i);
        if (check_value(json, &i) != VALID_VALUE)
            return (-1);
        (*nb_of_entries)++;
    } while (check_marker(json, &i, ',') == VALID_VALUE);
    marker = i;
    if (check_marker(json, &i, ']') == NOT_FOUND)
        return (-1);
    return (marker);
}

int get_next_ent_obj_idx(json_t json, int *nb_of_entries)
{
    int i = 0;
    int marker = 0;

    if (check_marker(json, &i, '{') == NOT_FOUND)
        return (-1);
    do {
        skip_white_spaces(json, &i);
        if (*nb_of_entries == 0 && json[i] == '}') {
            return (i);
        }
        if (check_routine_key_value(json, &i) != VALID_VALUE)
            return (-1);
        (*nb_of_entries)++;
    } while (check_marker(json, &i, ',') == VALID_VALUE);
    marker = i;
    if (check_marker(json, &i, '}') == NOT_FOUND)
        return (-1);
    return (marker);
}
