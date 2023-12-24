/*
** EPITECH PROJECT, 2020
** project
** File description:
** json
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "json.h"

void redirect_all_stdout(void);

Test(appendInt, test1)
{
    json_t new_json = init_json();

    append_long_int("", &new_json, "age", 5);
    cr_assert_str_eq(new_json, "{\"age\": 5}");
    free(new_json);
}

Test(appendTwoKeys, test2)
{
    json_t new_json = init_json();

    append_long_int("", &new_json, "age", 5);
    append_str("", &new_json, "name", "hugues");
    cr_assert_str_eq(new_json, "{\"age\": 5,\"name\": \"hugues\"}");
    free(new_json);
}

Test(appendObject, test3)
{
    json_t new_json = init_json();
    json_t new_json2 = init_json();

    append_long_int("", &new_json, "age", 5);
    append_str("", &new_json, "name", "hugues");
    append_obj("", &new_json2, "person", new_json);
    cr_assert_str_eq(new_json2, "{\"person\": {\"age\": 5,\"name\": \"hugues\"}}");

    free(new_json);
    free(new_json2);
}

Test(appendArray, test4)
{
    json_t new_json = init_json();
    long a[5] = {1, 2, 3, 4, END_OF_INT_ARRAY};

    append_long_int_array("", &new_json, "array", a);
    cr_assert_str_eq(new_json, "{\"array\": [1,2,3,4]}");
    free(new_json);
}

Test(appendObjArray, test5)
{
    json_t new_json = init_json();
    json_t new_json2[4] = {"{\"array\": [1,2,3,4]}", \
            "{\"person\": {\"age\": 5,\"name\": \"hugues\"}}", \
            "{\"age\": 5}", NULL};
    json_t expected_json = "{\"array\": [{\"array\": [1,2,3,4]},{\"person\": {\"age\": 5,\"name\": \"hugues\"}},{\"age\": 5}]}";
    append_obj_array("", &new_json, "array", new_json2);
    cr_assert_str_eq(new_json, expected_json);
    free(new_json);
}

Test(get_next_ent_idx, test6)
{
    int i = 0;
    json_t json = "[{\"coco\": 4}, {\"oui\": \"ok\"}]";

    cr_expect_eq(get_next_ent_idx(json, &i), 27);
    cr_expect_eq(json[27], ']');
    json = "[\"coco\", \"oui\"]";
    i = 0;
    cr_expect_eq(get_next_ent_idx(json, &i), 14);
}

Test(get_next_ent_idx, test7)
{
    json_t json = "{\"list\": [\"ui\",\"o\"]}";
    int nb_entries = 0;
    int pos = get_next_ent_idx(json + 9, &nb_entries);

    cr_expect_eq(pos, 9);
}