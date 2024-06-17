#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int value;
    struct Node *next;
} node;

// Function to create a new node
node *createNode(value)
{
    node *newNode = (node *)malloc(sizeof(node));

    newNode->value = value;
    newNode->next = NULL;

    return newNode;
};

// Function to add node to the end
node *addNode(node *head, int value)
{
    node *temp, *p;

    temp = createNode(value);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        };
        p->next = temp;
    }
    return head;
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

int main()
{
    return 0;
};