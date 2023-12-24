/*
** EPITECH PROJECT, 2020
** project
** File description:
** json
*/

#include "json.h"

int count_nb_of_element_in_array(json_t json, int i)
{
    int type = -1;
    int nb_element = 0;

    if (i == -1 || check_marker(json, &i, '[') == NOT_FOUND)
        return (-1);
    do {
        skip_white_spaces(json, &i);
        if (type == -1)
            type = check_type(json, &i);
        else if (type != check_type(json, &i)) {
            return (-1);
        }
        nb_element++;
    } while (check_marker(json, &i, ',') == VALID_VALUE);
    if (check_marker(json, &i, ']') == NOT_FOUND)
        return (-1);
    return (nb_element);
}

long *get_value_long_int_array(json_t json, char *key)
{
    int pos = find_json_key(json, key);
    int size = count_nb_of_element_in_array(json, pos);
    int i = 0;
    long *array;

    if (pos == -1 || size == -1)
        return (NULL);
    array = malloc(sizeof(long) * (size + 1));
    if (array == NULL)
        return (NULL);
    check_marker(json, &pos, '[');
    do {
        skip_white_spaces(json, &pos);
        array[i++] = get_long_int(&pos, json);
    } while (check_marker(json, &pos, ',') == VALID_VALUE);
    array[i] = 0xDEAD;
    return (array);
}

char **get_value_str_array(json_t json, char *key)
{
    int pos = find_json_key(json, key);
    int size = count_nb_of_element_in_array(json, pos);
    int i = 0;
    char **array;

    if (pos == -1 || size == -1)
        return (NULL);
    array = malloc(sizeof(char *) * (size + 1));
    if (array == NULL)
        return (NULL);
    check_marker(json, &pos, '[');
    do {
        skip_white_spaces(json, &pos);
        array[i++] = get_string(&pos, json, STR);
    } while (check_marker(json, &pos, ',') == VALID_VALUE);
    array[i] = NULL;
    return (array);
}

char **get_value_obj_array(json_t json, char *key)
{
    int pos = find_json_key(json, key);
    int size = count_nb_of_element_in_array(json, pos);
    int i = 0;
    char **array;

    if (pos == -1 || size == -1)
        return (NULL);
    array = malloc(sizeof(char *) * (size + 1));
    if (array == NULL)
        return (NULL);
    check_marker(json, &pos, '[');
    do {
        skip_white_spaces(json, &pos);
        array[i++] = get_string(&pos, json, OBJ);
    } while (check_marker(json, &pos, ',') == VALID_VALUE);
    array[i] = NULL;
    return (array);
}