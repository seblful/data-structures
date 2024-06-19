#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the structure for a node
typedef struct Node
{
    int key;
    char value[50];
    struct Node *next;
} node;

// Define the structure for HashTable
typedef struct HashTable
{
    node **arr;
    int size;
    int capacity;
} hashTable;

// Function to create a new node
node *createNode(int key, char *value)
{
    node *newNode = (node *)malloc(sizeof(node));

    newNode->key = key;
    strcpy(newNode->value, value);
    newNode->next = NULL;

    return newNode;
};

// Function to search value in list
bool searchValue(node *head, int key)
{
    while (head != NULL)
    {
        if (head->value == key)
            return true;
        head = head->next;
    };

    return false;
};

hashTable *createHashTable(int capacity)
{
    // Allocate memory for hash table
    hashTable *table = (hashTable *)malloc(sizeof(hashTable));
    // Allocate memory for table array and make all values NULL
    table->arr = (node **)malloc(sizeof(node *) * capacity);
    for (int i = 0; i < capacity; i++)
    {
        table->arr[i] = NULL;
    };

    table->size = 0;
    table->capacity = capacity;
    return table;
};

int hash(int key, int capacity)
{
    return key % capacity;
};

void insert(hashTable *table, int key, char *value)
{   
    node *newNode;

    int index = hash(key, table->capacity);
    

    // Create new node with key and value
    newNode = createNode(key, value);

    // Add node if index is empty
    if (table->arr[index] == NULL)
    {
        table->arr[index] = newNode;
    }
    else
    {   
        // Rewrite old value if key is the same
        if (table->arr[index]->key == key)
        {
            table->arr[index]->key = key;
            strcpy(table->arr[index]->value, value);
        }
        else
        {
            // Add node if index the same buy key is different
            newNode->next = table->arr[index];
            table->arr[index] = newNode;
        }
    };
};

bool get(hashTable *table, int key) {
    int index = hash(key, table->capacity);

    

};

char *get(hashTable *table, int key) {};

int main()
{
    hashTable *table;

    table = createHashTable(10);
    insert(table, 0, "John");
    printf("%d\n", table->arr[0]->key);
    printf("%s\n", table->arr[0]->value);
    insert(table, 0, "Mike");
    printf("%d\n", table->arr[0]->key);
    printf("%s\n", table->arr[0]->value);
    insert(table, 10, "Jane");
    printf("%d\n", table->arr[0]->key);
    printf("%s\n", table->arr[0]->value);


    // insert(table, 1, "Deer");
    // insert(table, 2, "Mone");
    // printf("%d\n", table->arr[1]->key);
    // printf("%s\n", table->arr[1]->value);

    // printf("%d\n", table->arr[0]->key);
    // printf("%s\n", table->arr[0]->value);
    return 0;
};