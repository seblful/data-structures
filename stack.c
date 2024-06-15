#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct Stack
{
    int items[MAX];
    int top;
} stack;

stack *createEmptyStack()
{
    stack *st = NULL;
    st = (stack *)malloc(sizeof(stack));
    st->top = -1;

    return st;
};

bool isEmpty(stack *st)
{
    if (st->top == -1)
    {
        return true;
    };

    return false;
};

bool isFull(stack *st)
{
    if (st->top + 1 >= MAX)
    {
        return true;
    };

    return false;
};

void push(stack *st, int value)
{
    if (isFull(st) == false)
    {
        st->top++;
        st->items[st->top] = value;
        printf("Value %d is pushed in stack.\n", value);
    }
    else
    {
        printf("Stack is full, impossible to push.\n");
    };
};

int pop(stack *st)
{
    int temp;

    if (isEmpty(st) == false)
    {
        temp = st->items[st->top];
        st->top--;
        printf("Value %d popped from the stack.\n", temp);
        return temp;
    }
    else
    {
        printf("Stack is empty, impossible to pop.\n");
        return 1;
    };
};

int peek(stack *st)
{
    return st->items[st->top];
};

void printStack(stack *st)
{
    if (isEmpty(st) == true)
    {
        printf("Stack is empty, nothing to print.\n");
    }
    else
    {
        printf("Stack:");
        for (int i = 0; i <= st->top; i++)
        {
            printf(" %d", st->items[i]);
        };
        printf(".\n");
    };
};

int main()
{
    // Create empty stack
    stack *st;
    st = createEmptyStack();

    // Push in stack
    push(st, 1);
    push(st, 2);
    push(st, 3);
    push(st, 4);
    push(st, 5);

    // Pop stack
    pop(st);
    pop(st);

    printStack(st);
    return 0;
};