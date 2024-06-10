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

node* addNode(node *head, int value) {
    // Declare temp and p
    node *temp, *p;
    
    // Create temp node
    temp = createNode(value);

    if (head == NULL) {
        head = temp;
    } else {
        p = head;

        // Find last node
        while (p->next != NULL) {
            p = p->next;
        };
        
        // Assign temp to last node
        p->next = temp;
    };

    return head;
};

void printList(node *head) {

    printf("Linked List: %d", head->value);
    
    while (head->next != NULL) {
        head = head->next;
        printf(" %d", head->value);
        
    };
};

int main() {
    node *head = NULL;

    for (int i=1; i<=10; i++) {
        head = addNode(head, i);
    };

    printList(head);
    return 0;
};