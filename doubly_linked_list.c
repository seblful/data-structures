# include <stdlib.h>
# include <stdio.h>

typedef struct Node {
    int value;
    struct Node *previous;
    struct Node *next;
} node;

node* createNode(int value) {
    node *newNode = NULL;
    newNode = (node*)malloc(sizeof(node));

    newNode->value = value;
    newNode->previous = NULL;
    newNode->next = NULL;

    return newNode;
};

void printList(node *head) {
    printf("Doubly Linked List: ");

    while (head != NULL) {
        printf("%d <-> ", head->value);
        head = head->next;
    };
};

node* addNode(node *head, int value) {
    node *temp, *p, *prev;

    temp = createNode(value);

    if (head == NULL) {
        head = temp;
    } else {
        p = head;

        while (p->next != NULL) {
            p = p->next;
        }

        p->next = temp;
        temp->previous = p;
    };

    return head;
};

int main() {
    node *head = NULL;
    
    for (int i=1; i<=7; i++) {
        head = addNode(head, i);
    };

    printList(head);

    return 0;
};