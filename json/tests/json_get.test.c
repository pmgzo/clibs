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

Test(findJsonKey, test1)
{
    json_t new_json = "{\"age\": 5,\"name\":  \"tobias\"}";

    cr_assert_eq(find_json_key(new_json, "name"), 19);
    cr_assert_eq(find_json_key(new_json, "tobias"), -1);
}

Test(getType, test2)
{
    json_t new_json = "{\"age\": 5,\"name\":  \"tobias\"}";

    cr_assert_eq(get_key_type(new_json, "name"), STR);
    cr_assert_eq(get_key_type(new_json, "nam"), UNDEFINED);

    new_json = "{\"age\": 5,\"refs\": [5, 8, 1]}";
    cr_assert_eq(get_key_type(new_json, "refs"), ARRAY);
}

Test(getStringAndInt, test3)
{
    json_t new_json = "{\"age\": 5,\"name\":  \"tobias\"}";
    int i = 19;
    char *str = get_string(&i, new_json, STR);

    cr_expect_str_eq(str, "tobias");
    cr_expect_eq(i, 27);
    i = 8;
    cr_expect_eq(get_long_int(&i, new_json), 5);
    cr_expect_eq(i, 9);
    free(str);
}

Test(getValueObj, test4)
{
    json_t new_json = "{\"age\": 5,\"name\": {\"coco\": \"pizza\"}}";
    char *str = get_value_obj("", new_json, "name");

    cr_expect_str_eq(str, "{\"coco\": \"pizza\"}");
    free(str);
}

Test(countNbOfElementInArray, test5)
{
    json_t new_json = "{\"series\": [5, 3, 4, 5]}";

    cr_expect_eq(count_nb_of_element_in_array(new_json, 11), 4);
    new_json = "{\"series\": [\"car\", \"toto\"]}";
    cr_expect_eq(count_nb_of_element_in_array(new_json, 11), 2);
}

Test(getValueIntArray, test6)
{
    json_t new_json = "{\"series\": [54, 3, 4, 5]}";
    long *i = get_value_long_int_array("", new_json, "series");

    cr_expect_eq(i[0], 54);
    cr_expect_eq(i[4], END_OF_INT_ARRAY);
    // cr_assert_arr_eq();
}

Test(getValueStrArray, test7)
{
    json_t new_json = "{\"series\": [\"54\", \"yaourt\", \"coco\"]}";
    char **i = get_value_str_array("", new_json, "series");

    cr_expect_str_eq(i[0], "54");
    cr_expect_str_eq(i[1], "yaourt");
    cr_expect_null(i[3]);
}

Test(getValueObjArray, test8)
{
    json_t new_json = "{\"series\": [{\"name\": \"whisky\"}, \
                        {\"name\": \"saumon\"}, \
                        {\"name\": \"ok\", \"arr\": [4, 5]}\
                        ]}";
    char **i = get_value_obj_array("", new_json, "series");

    cr_expect_str_eq(i[0], "{\"name\": \"whisky\"}");
    cr_expect_str_eq(i[2], "{\"name\": \"ok\", \"arr\": [4, 5]}");
    cr_expect_null(i[3]);
}

Test(getValueObjArrayTricky, test9)
{
    // json_t new_json = "{\"series2\": [{\"name\": \"whisky\"}, \
    //                     {\"name\": \"saumon\"}, \
    //                     {\"name\": \"ok\", \"arr\": [4, 5]}\
    //                     ]}";

    json_t new_json = "{\"users\": [{\"uuid\": \"de0ef41b-0122-4c98-8a43-63f342eca514\",\"name\": \"user\",\"date\": 1590662647}]}";
    char **i = get_value_obj_array("", new_json, "teams");

    cr_expect_null(i);
}

Test(key_match_in_obj_array, test10)
{
    json_t new_json = "{\"series\": [{\"name\": \"whisky\"}, \
                        {\"name\": \"saumon\"}, \
                        {\"name\": \"ok\", \"arr\": [4, 5]}\
                        ]}";

    cr_expect_eq(find_obj_with_key(new_json + 11, "name", "saumon"), 45);
    cr_expect_eq(find_obj_with_key(new_json + 11, "name", "ok"), 89);
    cr_expect_eq(find_obj_with_key(new_json + 11, "name", "whisky"), 1);
    cr_expect_eq(find_obj_with_key(new_json + 11, "name", "carote"), -1);
}