#include "json.h"

json_t create_historical_purchase(char *item_name, char *shopname, long rounded_price) {
    json_t new_json = init_json();

    append_str(&new_json, "item", item_name);
    append_str(&new_json, "shop", shopname);
    append_long_int(&new_json, "price", rounded_price);
    return new_json;
}

json_t create_address_json_obj(char *street, long street_number, char *state, char *country) {
    json_t address_json = init_json();

    append_str(&address_json, "street_name", street);
    append_long_int(&address_json, "street_number", street_number);
    append_str(&address_json, "country_state", state);
    append_str(&address_json, "country", country);
    return address_json;
}

int main() {

    json_t new_json = init_json();
    // add integer in json
    append_long_int(&new_json, "age", 30);
    
    // add string in json
    append_str(&new_json, "name", "James");

    char **array = malloc(sizeof(char*) * 3);
    array[0] = "Tom";
    array[1] = "Jason";
    array[2] = NULL;

    // add array of string in json
    append_str_array(&new_json, "friends", array);
    free(array);

    // add json obj within json
    json_t address = create_address_json_obj("Bulldog street", 547, "Ohio", "US");

    append_obj(&new_json, "address", address);
    free(address);

    // add array of json
    array = malloc(sizeof(json_t) * 4);
    array[0] = create_historical_purchase("hat", "HatShop", 40);
    array[1] = create_historical_purchase("shoes", "ShoeShop", 120);
    array[2] = create_historical_purchase("Winter Jacket", "JacketShop", 180);
    array[3] = NULL;

    append_obj_array(&new_json, "historical_purchases", array);

    free(array[0]);
    free(array[1]);
    free(array[2]);

    free(array);

    printf("new_json:\n %s\n", new_json);

    // get value from json
    printf("get age: %d\n", get_value_long_int(new_json, "age"));
    printf("get name: %s\n", get_value_str(new_json, "name"));
    printf("get value obj: %s\n", get_value_obj(new_json, "address"));

    free(new_json);
    return (0);
}