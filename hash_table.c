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
        table->size++;
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
            table->size++;
        }
    };
};

bool search(hashTable *table, int key) {

    int index = hash(key, table->capacity);

    // Return false if there is no node in array
    if (table->arr[index] == 0) {
        return false;
    };

    // Search every node by key
    node *lastNode;
    lastNode = table->arr[index];

    while (lastNode != NULL) {
        if (lastNode->key == key) {
            return true;
        }
        lastNode = lastNode->next;
    };

    return false;

};

char *get(hashTable *table, int key) {};

int main()
{
    hashTable *table;
    int searchKey = 3;

    // Create table
    table = createHashTable(10);

    // Insert
    insert(table, 0, "John");
    insert(table, 0, "Mike");
    insert(table, 10, "Jane");
    insert(table, 1, "Deer");
    insert(table, 2, "Mone");


    // Search
    if (search(table, searchKey) == true) {
        printf("Key %d was found in the table.\n", searchKey);
    }
    else {
        printf("Key %d was not found in the table.\n", searchKey);
    };

    return 0;
};