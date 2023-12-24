/*
** EPITECH PROJECT, 2020
** project
** File description:
** json
*/

#include "json.h"
#include "json_find.h"

int browse_object_effectiv(char *str, int *i, char *searching_key)
{
    int indicator = 0;
    int pos = -1;

    if (check_marker(str, i, '{') == NOT_FOUND)
        return (-1);
    do {
        skip_white_spaces(str, i);
        if (find_key_in_entry(str, i, searching_key, &pos) != VALID_VALUE)
            return (-1);
        indicator = check_marker(str, i, ',');
    } while (indicator == VALID_VALUE);
    if (check_marker(str, i, '}') == NOT_FOUND)
        return (-1);
    return (pos);
}

int compare_key_str(json_t json, int *i, char *key, char *exptd_value)
{
    int pos = 0;
    int size;

    if ((pos = browse_object_effectiv(json, i, key)) != -1) {
        size = strlen(exptd_value);
        if (strncmp(json + pos, exptd_value, size) == 0) {
            return (0);
        }
    }
    return (1);
}

int key_match_in_obj_array(json_t json, char *key, char *expected_value)
{
    int i = 0;
    int tmp = 0;

    if (check_marker(json, &i, '[') == NOT_FOUND)
        return (-1);
    do {
        skip_white_spaces(json, &i);
        tmp = i;
        if (compare_key_str(json, &i, key, expected_value) == 0)
            return (tmp);
    } while (check_marker(json, &i, ',') == VALID_VALUE);
    if (check_marker(json, &i, ']') == NOT_FOUND)
        return (-1);
    return (-1);
}

int find_obj_with_key(json_t json, char *key, char *expected_value)
{
    char *format_key = formatize_str(key);
    char *format_exptd_val = formatize_str(expected_value);
    int value;

    if (!format_key || !expected_value)
        return (-1);
    value = key_match_in_obj_array(json, format_key, format_exptd_val);
    free(format_key);
    free(format_exptd_val);
    return (value);
}