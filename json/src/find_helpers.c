/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include <stdio.h>

char *formatize_str(char *str)
{
    char *formatized_key = NULL;

    asprintf(&formatized_key, "\"%s\"", str);
    return (formatized_key);
}
