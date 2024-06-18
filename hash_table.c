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
typedef struct HashTable {
    node **arr;
    int size;
    int capacity;
} hashTable;

// Function to create a new node
node *createNode(int key, char *value)
{
    node *newNode = (node *)malloc(sizeof(node));

    newNode->key = key;
    //newNode->value = value;
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

hashTable *createHashTable(int capacity) {
    hashTable *table = (hashTable*) malloc(sizeof(hashTable));
    table->arr = (node**)malloc(sizeof(node*) * capacity);
    table->size = 0;
    table->capacity = capacity;
    return table;
};

int hash(int key, int capacity)
{
    return key % capacity;
};

void insert(hashTable *table, int key, char *value) {
    int index = hash(key, table->capacity);
    node *newNode;

    newNode = createNode(key, value);

    if (table->arr[index] == NULL) {
        table->arr[index] = newNode;
    }
    else {
        node *temp;
        temp = table->arr[index];

        while (temp->next != NULL) {
            temp = temp->next;
        };

        temp->next = newNode;
    }
    
    
};

int main()
{
    hashTable *table;

    table = createHashTable(10);
    insert(table, 0, "John");
    
    return 0;
};