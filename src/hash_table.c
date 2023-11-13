#include "hash_table.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

HashTable* hash_table_create(unsigned int bucket_count, unsigned long(hash_fn)(void*)) {
    HashTable* hash_table = (HashTable*)malloc(sizeof(HashTable) + bucket_count * sizeof(LinkedListNode));
    if (!hash_table) {
        fprintf(stderr, "hash_table_create: Memory allocation failure!\n");
        exit(EXIT_FAILURE);
    }

    hash_table->hash_fn = hash_fn;
    hash_table->bucket_count = bucket_count;

    for (int i = 0; i < bucket_count; i++) {
        hash_table->buckets[i] = NULL;
    }

    return hash_table;
}

void hash_table_free(HashTable* hash_table) {
    for (int i = 0; i < hash_table->bucket_count; i++) {
        linked_list_free(hash_table->buckets[i]);
        hash_table->buckets[i] = NULL;
    }

    hash_table->hash_fn = NULL;

    free(hash_table);
}
