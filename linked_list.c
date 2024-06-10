# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} node;

node* createNode(int value) {
    node *temp = NULL;
    temp = malloc(sizeof(node));

    temp->value = value;
    temp->next = NULL;

    return temp;
};

void addNode(int value) {
    int a;
    a = 5;
};

void printList(node *head) {
    node *temp;

    temp = head;

    printf("Linked List: %d", temp->value);
    
    while (temp->next != NULL) {
        temp = temp->next;
        printf(" %d", temp->value);
        
    };
};

int main() {
    node *head;
    node *one;
    node *two;

    one = createNode(1);
    two = createNode(2);

    one->next = two;

    head = one;
    printList(head);
    return 0;
};