#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node in the linked list
typedef struct Node
{
    int value;
    struct Node *next;
} node;

// Function to create a new node
node *createNode(int value)
{
    node *newNode = NULL;
    newNode = malloc(sizeof(node));

    newNode->value = value;
    newNode->next = NULL;

    return newNode;
};

// Function to add node to the end
node *addNode(node *head, int value)
{
    // Declare temp and p
    node *temp, *p;

    // Create temp node
    temp = createNode(value);

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;

        // Find last node
        while (p->next != NULL)
        {
            p = p->next;
        };

        // Assign temp to last node
        p->next = temp;
    };

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

// Function to clear list
void clearList(node *head)
{
    node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to print values of the list
void printList(node *head)
{

    printf("Linked List: ");

    while (head != NULL)
    {
        printf("%d -> ", head->value);
        head = head->next;
    };
    printf("\n");
};

int main()
{
    node *head = NULL;
    int searchKey = 2;
    bool search;

    for (int i = 1; i <= 100; i++)
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
    // printList(head);

    return 0;
};