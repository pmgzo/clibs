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

Test(parsingJsonWithASingleKey, test1)
{
    json_t json = "{\"key\": \"value\"}";
    int i = 0;

    cr_assert_eq(json_is_valid(json), VALID_JSON);
}

Test(stringCheck, test)
{
    json_t json = "{\"key\": \"value\",}";
    int i = 1;

    cr_expect_eq(string_checker(json, &i), VALID_VALUE);
    cr_expect_eq(i, 6);
    i = 8;
    cr_expect_eq(string_checker(json, &i), VALID_VALUE);
    cr_expect_eq(i, 15);
}

Test(numberCheck, test)
{
    json_t json = "{\"key\": 10}";
    int i = 8;

    cr_expect_eq(number_checker(json, &i), VALID_VALUE);
    cr_expect_eq(i, 10);
}

Test(objectCheck, test)
{
    json_t json = "{\"key\": 10}";
    int i = 0;

    cr_expect_eq(object_checker(json, &i), VALID_VALUE);
    cr_expect_eq(i, 11);
}

Test(arrayCheck, test)
{
    json_t json = "{\"keys\": [5, 2, 2]}";
    int i = 9;

    cr_expect_eq(array_checker(json, &i), VALID_VALUE);
}

Test(advancedJsonIsValidTest, test)
{
    json_t json = "{\"keys\": [5, 2, 2], \
                            \"array\": [{\"chocolat\": \"ok\"}, {\"cornflakes\": \"oui\"}], \"array2\": [\"poivre\", \"saucisson\"]}";
    cr_expect_eq(json_is_valid(json), VALID_JSON);
}
