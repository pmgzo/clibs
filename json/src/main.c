/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "json.h"
#include "json_parser.h"

int main()
{
    //append_array, find_object_from_key, 
    json_t new_json = init_json();
    // json_t new_json2 = init_json();

    // append_int("", &new_json, "age", 5);
    // append_str("", &new_json, "name", "hugues");
    // append_obj("", &new_json2, "person", new_json);

    int a[5] = {1, 2, 3, 4, END_OF_INT_ARRAY};

    // append_int_array("", &new_json, "array", a);
    append_long_int_array("", &new_json, "array", {});
    


    free(new_json);
    // free(new_json2);
}
