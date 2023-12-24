/*
** EPITECH PROJECT, 2020
** project
** File description:
** json
*/

#ifndef JSON_PARSER_H_
#define JSON_PARSER_H_

#define EOJSON -1

#define RIGHT_CHAR 0
#define NOT_FOUND 2

#define VALID_VALUE 3

#define SYNTAX_ERROR 1
#define ERROR_TYPE_ARRAY 2

#define INVALID_JSON 1
#define VALID_JSON 0

#include "json_type.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*fct_pt_value_checker)(char *, int *);

int object_checker(char *str, int *i);
int string_checker(char *str, int *i);
int number_checker(char *str, int *i);
int array_checker(char *str, int *i);

static fct_pt_value_checker array_value_checker[4] = {
    &string_checker,
    &number_checker,
    &object_checker,
    &array_checker
};

int json_is_valid(json_t json);

int check_value(char *str, int *i);
int check_key(char *str, int *i);
int check_routine_key_value(char *str, int *i);

void jump_digit(char *line, int *i);
void skip_white_spaces(char *line, int *i);
int check_marker(char *str, int *i, char token);

enum Type check_type(char *str, int *i);

#endif