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

void hash_table_add(HashTable* hash_table, void* key, void* value) {
    if (!hash_table) {
        return;
    }

    unsigned long bucket_ix = hash_table->hash_fn(key);

    HashTableItem* item = malloc(sizeof *item);
    if (!item) {
        return;
    }

    item->key = key;
    item->value = value;
    
    if (!hash_table->buckets[bucket_ix]) {
        hash_table->buckets[bucket_ix] = linked_list_node_create(item);
        return;
    }

    linked_list_node_append(hash_table->buckets[bucket_ix], item);
}

void* hash_table_get(HashTable* hash_table, void* key) {
    if (!hash_table) {
        return NULL;
    }

    unsigned long bucket_ix = hash_table->hash_fn(key);
    if (bucket_ix >= hash_table->bucket_count) {
        return NULL;
    }

    LinkedListNode* node = hash_table->buckets[bucket_ix];
    while (node) {
        HashTableItem* item = (HashTableItem*)node;
        if (item->key == key) {
            return item->value;
        }

        node = node->next;
    }

    return NULL;
}

void hash_table_free(HashTable* hash_table) {
    for (int i = 0; i < hash_table->bucket_count; i++) {
        linked_list_free(hash_table->buckets[i]);
        hash_table->buckets[i] = NULL;
    }

    hash_table->hash_fn = NULL;

    free(hash_table);
}
