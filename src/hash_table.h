#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "linked_list.h"

struct HashTable {
    unsigned int bucket_count;
    unsigned long (*hash_fn)(void* data);
    struct LinkedListNode* buckets[];
};

typedef struct HashTable HashTable;

struct HashTableItem {
    void* key;
    void* value;
};

typedef struct HashTableItem HashTableItem;

HashTable* hash_table_create(unsigned int bucket_count, unsigned long(hash_fn)(void*));

void hash_table_add(HashTable* hash_table, void* key, void* value);

void* hash_table_get(HashTable* hash_table, void* key);

void hash_table_free(HashTable* hash_table);

#endif

