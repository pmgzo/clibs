#include "list.h"
#include <stdio.h>

void display_linked_list(list_t *list) {
    list_t *first_element = list;

    do {
        printf("%d", *((int *)list->data));
        first_become_last(&list);
    } while(list != first_element);
    printf("\n");
}

void clear_up_linked_list(list_t **list) {
    while (*list) {
        free((*list)->data);
        remove_element(list);
    }
}

void reverse_link_list(list_t **list)
{
    list_t *new_list = NULL;
    while ((*list) != NULL) {
        // insert first element of in to new_list
        insert_element(list, &new_list);
    }
    *list = new_list;
}

int is_pair(int value) {
    return !(value % 2);
}

int filter_pair_number(void *data) {
    return is_pair(*((int *) data));
}

int main() {
    list_t *new_list = NULL;
    
    // build list
    for (int i = 0; i < 10; i++) {
        if (handle_add_element(&new_list) == 84) {
            printf("Error has occured, can't add element to linked list");
            return (1);
        }
        int *value = malloc(sizeof(int)); 
        *value = i;
        new_list->data = (void *) value;
    }
    printf("built list:\n");
    display_linked_list(new_list);
    
    printf("list size = %d\n", return_size_list(&new_list));

    // reverse link list
    printf("reversing linked list:\n");
    reverse_link_list(&new_list);
    display_linked_list(new_list);

    // filter pair number
    printf("filter out linked list:\n");
    filter_list(&new_list, filter_pair_number); // memory leak here doesn't clean the data
    display_linked_list(new_list);

    // swaping two first element
    printf("swapping two first element:\n");
    swap_first_element(&new_list);
    display_linked_list(new_list);

    // clear ressources
    clear_up_linked_list(&new_list);

    return (0);
}