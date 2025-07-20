#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char *key;
    int value;
    struct node *next;
};

struct hashtable{
    struct node **table;
};

int hash(char* key){
    int val = 0;
    while(*key){
        val = (val*31 + *key++)%10;
    }
    return val;
}

struct hashtable *createtable(){
    struct hashtable* ht = malloc(sizeof(struct hashtable));
    ht->table = malloc(sizeof(struct node*)*10);
    for(int i=0;i<10;i++){
        ht->table[i] = NULL;
    } 
    return ht;
}

void insert(struct hashtable *ht, const char* key, int value){
    int index = hash(key);
    struct node* newnode = malloc(sizeof(struct node));
    newnode->key = strdup(key);
    newnode->value = value;
    newnode->next = ht->table[index];
    ht->table[index] = newnode;
}

int search(struct hashtable *ht, const char *key){
    int index = hash(key);
    struct node* current = ht->table[index];
    while(current){
        if (strcmp(current->key,key)==0){
            return current->key;
        }
        current = current->next;
    }
    return -1;
}

void delete(struct hashtable *ht, const char *key){
    int index = hash(key);
    struct node *current = ht->table[index];
    struct node *prev = NULL;
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