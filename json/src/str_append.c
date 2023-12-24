/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json_append.h"

char *str_append(char *dest, char *src)
{
    int size = strlen(src);
    int size2 = strlen(dest);
    char *str = malloc(sizeof(char) * (size + size2 + 1));
    int i2 = 0;
    int i = 0;

    if (str == NULL)
        return (NULL);
    while (i < (size + size2)) {
        if (i < size2)
            str[i] = dest[i];
        else {
            str[i] = src[i2];
            i2++;
        }
        i++;
    }
    str[i] = 0;
    return (str);
}
