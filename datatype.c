//datatype.c
#include "datatype.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Initialise a key object.
Key key_ini() {
    Key new_key = (Key) malloc(sizeof(Key_struct));
    if (new_key == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(0);
    }
    new_key->key1 = NULL;
    new_key->key2 = 0;
    return new_key;
}

// Set the value of a key object
void key_set(Key key, Key1 string, Key2 integer) {
    key->key1 = strdup(string);
    key->key2 = integer;
}
//datatype.c
int key_comp(Key keya, Key keyb) {
    int str_comp = strcmp(keya->key1, keyb->key1);
    if (str_comp == 0) {
        int comp = keya->key2 - keyb->key2;
        if (comp > 0) {
            return 1;
        } else if (comp < 0) {
            return -1;
        } else {
            return 0;
        }
    } else {
        return str_comp;
    }
}

void key_print2(Key key) {
    printf("%-20d %-20s", key->key2, key->key1);}
void key_free(Key key) {
    free(key->key1);
    free(key);}
Data data_ini() {
    Data new_data = (Data) malloc(sizeof(float));
    *new_data = 0.0;
    return new_data;}
void data_set(Data data, float intdata) {*data = intdata;}
void data_print(Data data) {printf("%5.0f\n", *data);}
void data_free(Data data) {free(data);}
//
