/*
** EPITECH PROJECT, 2020
** project
** File description:
** json
*/

#include "json.h"
#include "json_parser.h"

int string_checker(char *str, int *i)
{
    if (str[*i] != '\"') {
        return (NOT_FOUND);
    }
    (*i)++;
    while (str[*i]) {
        if (str[*i] == '\"') {
            (*i)++;
            return (VALID_VALUE);
        }
        (*i)++;
    }
    return (SYNTAX_ERROR);
}

int number_checker(char *str, int *i)
{
    int tmp = 0;

    if (str[*i] == '-')
        (*i)++;
    tmp = *i;
    jump_digit(str, i);
    if (tmp == *i)
        return (NOT_FOUND);
    return (VALID_VALUE);
}

int object_checker(char *str, int *i)
{
    int indicator = 0;

    if (check_marker(str, i, '{') == NOT_FOUND)
        return (NOT_FOUND);
    do {
        skip_white_spaces(str, i);
        if (check_routine_key_value(str, i) != VALID_VALUE)
            return (SYNTAX_ERROR);
        indicator = check_marker(str, i, ',');
    } while (indicator == VALID_VALUE);
    if (check_marker(str, i, '}') == NOT_FOUND)
        return (SYNTAX_ERROR);
    return (VALID_VALUE);
}

int array_checker(char *str, int *i)
{
    int type = -1;
    int indicator = 0;

    if (check_marker(str, i, '[') == NOT_FOUND)
        return (NOT_FOUND);
    do {
        skip_white_spaces(str, i);
        if (type == -1 && check_marker(str, i, ']') == VALID_VALUE)
            return (VALID_VALUE);
        if (type == -1)
            type = check_type(str, i);
        else if (type != check_type(str, i)) {
            return (ERROR_TYPE_ARRAY);
        }
        indicator = check_marker(str, i, ',');
    } while (indicator == VALID_VALUE);
    if (check_marker(str, i, ']') == NOT_FOUND)
        return (SYNTAX_ERROR);
    return (VALID_VALUE);
}

enum Type check_type(char *str, int *i)
{
    if (object_checker(str, i) == VALID_VALUE) {
        return (OBJ);
    }
    if (array_checker(str, i) == VALID_VALUE) {
        return (ARRAY);
    }
    if (string_checker(str, i) == VALID_VALUE) {
        return (STR);
    }
    if (number_checker(str, i) == VALID_VALUE) {
        return (NUMBER);
    }
    return UNDEFINED;
}