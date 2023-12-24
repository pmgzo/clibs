/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include <stdio.h>

char *create_entry_number(char *key, long value)
{
    char *new_entry;

    asprintf(&new_entry, "\"%s\": %ld", key, value);
    return (new_entry);
}

char *create_entry_str(char *key, char *str)
{
    char *new_entry;

    asprintf(&new_entry, "\"%s\": \"%s\"", key, str);
    return (new_entry);
}

char *create_entry(char *key, char *str)
{
    char *new_entry;

    asprintf(&new_entry, "\"%s\": %s", key, str);
    return (new_entry);
}
