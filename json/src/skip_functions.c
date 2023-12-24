/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

void jump_equal(char *line, int *i, char c)
{
    while (line[*i] != 0 && line[*i] == c)
        (*i)++;
}

void jump_different(char *line, int *i, char c)
{
    while (line[*i] != 0 && line[*i] != c)
        (*i)++;
}

void jump_digit(char *line, int *i)
{
    while (line[*i] != 0
        && line[*i] >= '0' && line[*i] <= '9') {
            (*i)++;
    }
}

void skip_white_spaces(char *line, int *i)
{
    while (line[*i] != 0 && (line[*i] == '\n' ||
        line[*i] == '\t' || line[*i] == ' ')) {
        (*i)++;
    }
}
