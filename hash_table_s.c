#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a hash table
typedef struct
{
    int key;
    char value[100];
} HashTableElement;

// Define the structure for the hash table
typedef struct
{
    HashTableElement *elements;
    int size;
    int capacity;
} HashTable;

// Function to calculate the hash value
int hash(int key, int capacity)
{
    return key % capacity;
}

// Function to create a new hash table
HashTable *createHashTable(int capacity)
{
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->elements = (HashTableElement *)malloc(sizeof(HashTableElement) * capacity);
    table->size = 0;
    table->capacity = capacity;
    return table;
}

// Function to insert a new element into the hash table
void insert(HashTable *table, int key, char *value)
{
    int index = hash(key, table->capacity);
    for (int i = 0; i < table->capacity; i++)
    {
        if (table->elements[index].key == -1)
        {
            table->elements[index].key = key;
            strcpy(table->elements[index].value, value);
            table->size++;
            return;
        }
        if (table->elements[index].key == key)
        {
            strcpy(table->elements[index].value, value);
            return;
        }
        index = (index + 1) % table->capacity;
    }
}

// Function to retrieve a value from the hash table
char *get(HashTable *table, int key)
{
    int index = hash(key, table->capacity);
    for (int i = 0; i < table->capacity; i++)
    {
        if (table->elements[index].key == key)
        {
            return table->elements[index].value;
        }
        index = (index + 1) % table->capacity;
    }
    return NULL;
}

// Function to free the memory allocated for the hash table
void freeHashTable(HashTable *table)
{
    free(table->elements);
    free(table);
}

int main()
{
    HashTable *table = createHashTable(10);
    insert(table, 1, "Hello");
    insert(table, 2, "World");
    insert(table, 3, "This");
    insert(table, 4, "Is");
    insert(table, 5, "A");
    insert(table, 6, "Hash");
    insert(table, 7, "Table");

    printf("%s\n", get(table, 1));
    printf("%s\n", get(table, 2));
    printf("%s\n", get(table, 3));
    printf("%s\n", get(table, 4));
    printf("%s\n", get(table, 5));
    printf("%s\n", get(table, 6));
    printf("%s\n", get(table, 7));

    freeHashTable(table);

    return 0;
}