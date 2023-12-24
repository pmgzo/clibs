/*
** EPITECH PROJECT, 2020
** project
** File description:
** json
*/

#include "json.h"

json_t init_json(void)
{
    json_t new_json = malloc(sizeof(char) * 3);
    if (new_json == NULL) {
        return (NULL);
    }
    new_json[0] = '{';
    new_json[1] = '}';
    new_json[2] = '\0';
    return (new_json);
}