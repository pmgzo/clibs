/*
** EPITECH PROJECT, 2020
** project
** File description:
** json
*/

#ifndef JSON_TYPE_H
#define JSON_TYPE_H

#define JSON_APPEND_FAILED 1
#define JSON_APPEND_SUCCEED 0



enum Type {
    OBJ,
    STR,
    NUMBER,
    ARRAY,
    UNDEFINED
};

typedef char * json_t;

#endif