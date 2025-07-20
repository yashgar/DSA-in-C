#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

struct Node {
    char *key;
    int value;
    struct Node *next;
};

struct HashTable {
    struct Node **table;
};

int hash(const char *key) {
    int hash_value = 0;
    while (*key) {
        hash_value = (hash_value * 31 + *key++) % TABLE_SIZE;
    }
    return hash_value;
}

struct HashTable *create_table() {
    struct HashTable *ht = malloc(sizeof(struct HashTable));
    ht->table = malloc(sizeof(struct Node *) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void insert(struct HashTable *ht, const char *key, int value) {
    int index = hash(key);
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = ht->table[index];
    ht->table[index] = new_node;
}

int search(struct HashTable *ht, const char *key) {
    int index = hash(key);
    struct Node *current = ht->table[index];
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Not found
}

void delete(struct HashTable *ht, const char *key) {
    int index = hash(key);
    struct Node *current = ht->table[index];
    struct Node *prev = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                ht->table[index] = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void free_table(struct HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node *current = ht->table[i];
        while (current) {
            struct Node *temp = current;
            current = current->next;
            free(temp->key);
 free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

int main() {
    struct HashTable *ht = create_table();
    insert(ht, "key1", 1);
    insert(ht, "key2", 2);
    printf("Value for key1: %d\n", search(ht, "key1"));
    printf("Value for key2: %d\n", search(ht, "key2"));
    delete(ht, "key1");
    printf("Value for key1 after deletion: %d\n", search(ht, "key1"));
    free_table(ht);
    return 0;
}