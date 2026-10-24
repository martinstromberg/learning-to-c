#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hash_table.h"

unsigned long hash_fn(void* data) {
    char* characters = (char*)data;

    int char_code = (int)characters[0];

    return (unsigned long)(char_code % 26);
}

int main() {
    srand(time(NULL)); // initializes srand, call only once
    
    HashTable* hash_table = hash_table_create(26, hash_fn);

    char key[4] = { 'b', 'a', 'r', '\0' };
    char expected[4] = { 'f', 'o', 'o', '\0' };
    hash_table_add(hash_table, key, expected);

    char* actual = (char*)hash_table_get(hash_table, key);

    char actual_sz[4];
    for (int i = 0; i < 4; i++) {
        actual_sz[i] = actual[i];
    }
    printf("%s\n", actual_sz);
    
    return 0;
}
