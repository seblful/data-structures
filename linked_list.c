# include <stdio.h>
# include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int value;
    struct Node *next;
} node;

// Function to create a new node
node* createNode(int value) {
    node *newNode = NULL;
    newNode = malloc(sizeof(node));

    newNode->value = value;
    newNode->next = NULL;

    return newNode;
};

void addNode(int value) {
    int a;
    a = 5;
};

void printList(node *head) {

    printf("Linked List: %d", head->value);
    
    while (head->next != NULL) {
        head = head->next;
        printf(" %d", head->value);
        
    };
};

int main() {
    node *head;
    node *temp;
    node *n;

    

    n = createNode(0);
    head = n;
    temp = n;

    for (int i = 1; i<6; i++) {
        n = createNode(i);
        temp->next = n;
        temp = temp->next;

    };

    printList(head);
    return 0;
};