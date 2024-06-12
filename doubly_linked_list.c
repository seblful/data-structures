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
        printf("%d <->", head->value);
        head = head->next;
    };
};

node* addNode(node *head, int value) {
    node *temp, *p, *prev;

    temp = createNode(value);

    if (head == NULL) {
        head = temp;
    } else {
        p = temp;

        while (p->next != NULL) {
            p = p->next;
        }

        p->next = temp;
    };

    return head;
};

int main() {
    node *head;
    
    head = createNode(1);

    printList(head);

    return 0;
};