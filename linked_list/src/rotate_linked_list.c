#include "list.h"



int first_become_last(list_t **tab)
{
    list_t *first_element;

    if ((*tab) == NULL)
        return (84);
    first_element = (*tab)->next;
    if ((*tab)->next != *tab)
        *tab = first_element;
    return (0);
}

int last_become_first(list_t **tab)
{
    list_t *first_element;

    if ((*tab) == NULL)
        return (84);
    first_element = (*tab)->prev;
    if ((*tab)->prev != *tab)
        *tab = first_element;
    return (0);
}
