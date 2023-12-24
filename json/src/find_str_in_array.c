/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json_parser.h"
#include "json_find.h"

int compare_value_str(json_t json, char *expected_value, int *i)
{
    int size = strlen(expected_value);

    if (strncmp(json + *i, expected_value, size) == 0) {
        return (0);
    }
    if (check_marker(json + *i + 1, i, '\"') == NOT_FOUND)
        return (-1);
    return (1);
}

int find_in_json_array_str(json_t json, char *value)
{
    int i = 0;
    int ret = 0;
    int tmp = 0;

    if (check_marker(json, &i, '[') == NOT_FOUND)
        return (-1);
    do {
        skip_white_spaces(json, &i);
        tmp = i;
        if ((ret = compare_value_str(json, value, &i)) == -1)
            return (-1);
        if (ret == 0)
            return (tmp);
        i++;
    } while (check_marker(json, &i, ',') == VALID_VALUE);
    if (check_marker(json, &i, ']') == NOT_FOUND)
        return (-1);
    return (-1);
}

int find_str_in_array(json_t json, char *value)
{
    char *formatted_value = formatize_str(value);
    int ret = find_in_json_array_str(json, formatted_value);

    free(formatted_value);
    return (ret);
}
