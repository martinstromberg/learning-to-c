#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#import "linked_list.h"

struct HashTable {
    unsigned int bucket_count;
    unsigned long (*hash_fn)(void* data);
    struct LinkedListNode* buckets[];
};
// Wait I just realized this way I have no way of connecting a hash value to a 
// particular bucket... I'll have to figure this out tomorrow.

typedef struct HashTable HashTable;

HashTable* hash_table_create(unsigned int bucket_count, unsigned long(hash_fn)(void*));

#endif

