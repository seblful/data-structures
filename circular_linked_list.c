#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Define the structure for a node in the doubly linked list
typedef struct Node
{
    int value;
    struct Node *next;
} node;

// Function to create a new node
node *createNode(int value)
{
    node *newNode = NULL;
    newNode = (node *)malloc(sizeof(node));

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
        head->next = head;
    }
    else
    {
        p = head;

        while (p->next != head)
        {
            p = p->next;
        }

        p->next = temp;
        temp->next = head;
    };

    return head;
};

// Function to search value in list
bool searchValue(node *head, int key)
{
    node *temp;

    temp = head;

    do
    {
        if (temp->value == key)
        {
            return true;
        };
        temp = temp->next;
    } while (temp != head);

    return false;
};

// Function to clear list
void clearList(node *head)
{
    node *current = head;
    node *next = NULL;

    // Traverse the list until we reach the head node again
    while (current != head || next != head)
    {
        next = current->next;
        free(current);
        current = next;
    }
};

void printList(node *head)
{
    node *temp;

    temp = head;

    printf("Circular Linked List: -> ");

    do
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
};

int main()
{
    node *head = NULL;
    int searchKey = 2;
    bool search;

    for (int i = 1; i <= 7; i++)
    {
        head = addNode(head, i);
    };

    // Print values of linked list
    printList(head);

    // Search value in linked list
    search = searchValue(head, searchKey);

    if (search == true)
    {
        printf("Value %d is in list.\n", searchKey);
    }
    else
    {
        printf("Value %d is not in list.\n", searchKey);
    };

    // Clear list
    printf("Size of the head before clear is %d.\n", sizeof(head));
    clearList(head);
    printf("Size of the head after clear is %d.\n", sizeof(head));
    printList(head);

    return 0;
};