/*
** EPITECH PROJECT, 2020
** project
** File description:
** json
*/

#ifndef JSON_H
#define JSON_H

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "json_parser.h"

#define END_OF_INT_ARRAY 0xDEAD

json_t init_json(void);

int append_long_int(json_t *json, char *key, long value);
int append_str(json_t *json, char *key, char *value);
int append_obj(json_t *json, char *key, json_t value);
int append_obj_array(json_t *json, char *key, json_t *obj_array);
int append_str_array(json_t *json, char *key, char **array);
int append_long_int_array(json_t *json, char *key, long *array);

int insert_first_entry(json_t newjson, json_t oldjson, json_t entry, int i);
int insert_entry(json_t newjson, json_t oldjson, json_t entry, int i);

int get_next_ent_idx(json_t json, int *nb_of_entries);
int get_next_ent_obj_idx(json_t json, int *nb_of_entries);

int find_json_key(json_t json, char *key);

int get_key_type(json_t json, char *key);

//helpers
char *get_string(int *i2, json_t json, int expected_type);
long get_long_int(int *i2, json_t json);

//functions
long get_value_long_int(json_t json, char *key);
char *get_value_str(json_t json, char *key);
json_t get_value_obj(json_t json, char *key);

int count_nb_of_element_in_array(json_t json, int i);
long *get_value_long_int_array(json_t json, char *key);
char **get_value_str_array(json_t json, char *key);
char **get_value_obj_array(json_t json, char *key);

int find_obj_with_key(json_t json, char *key, char *expected_value);
int find_str_in_array(json_t json, char *value);

#endif