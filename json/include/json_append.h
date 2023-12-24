/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#ifndef JSON_APPEND_H_
#define JSON_APPEND_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "json_type.h"

char *str_append(char *dest, char *src);

char *create_entry_number(char *key, long value);
char *create_entry_str(char *key, char *str);
char *create_entry(char *key, char *str);

json_t build_json_long_int_array(long *array);
json_t build_json_str_array(char **array);
json_t build_json_obj_array(char **array);

json_t create_array_int_entry(char *key, long *array);
json_t create_array_str_entry(char *key, char **array);
json_t create_array_obj_entry(char *key, char **array);

int append_entry(json_t *json, json_t new_entry);

#endif
