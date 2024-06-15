#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

typedef struct Queue
{
    int front;
    int rear;
    int items[SIZE];
} queue;

queue *createEmptyQueue()
{
    queue *qe = (queue *)malloc(sizeof(queue));
    qe->front = -1;
    qe->rear = -1;
    return qe;
}

bool isEmpty(queue *qe)
{
    return qe->front == -1;
}

bool isFull(queue *qe)
{
    return (qe->rear + 1) % SIZE == qe->front;
}

void enqueue(queue *qe, int value)
{
    if (!isFull(qe))
    {
        if (qe->front == -1)
        {
            qe->front = 0;
        }
        qe->rear = (qe->rear + 1) % SIZE;
        qe->items[qe->rear] = value;
        printf("Value %d enqueued to the queue.\n", value);
    }
    else
    {
        printf("Queue is full, impossible to enqueue.\n");
    }
}

int dequeue(queue *qe)
{
    if (!isEmpty(qe))
    {
        int temp = qe->items[qe->front];
        if (qe->front == qe->rear)
        {
            // Queue is now empty
            qe->front = qe->rear = -1;
        }
        else
        {
            qe->front = (qe->front + 1) % SIZE;
        }
        printf("Value %d dequeued from the queue.\n", temp);
        return temp;
    }
    else
    {
        printf("Queue is empty, nothing to dequeue.\n");
        return -1; // Changed to return a more indicative error value
    }
}

int peek(queue *qe)
{
    if (!isEmpty(qe))
    {
        int temp = qe->items[qe->front];
        printf("Value %d peeked from the queue.\n", temp);
        return temp;
    }
    else
    {
        printf("Queue is empty, nothing to peek.\n");
        return -1; // Changed to return a more indicative error value
    }
}

void printQueue(queue *qe)
{
    if (isEmpty(qe))
    {
        printf("Queue is empty, nothing to print.\n");
    }
    else
    {
        printf("Queue: FRONT->");
        for (int i = qe->front; i != qe->rear; i = (i + 1) % SIZE)
        {
            printf(" %d", qe->items[i]);
        }
        printf(" %d <-REAR.\n", qe->items[qe->rear]);
    }
}

int main()
{
    queue *qe = createEmptyQueue();

    // Enqueue
    enqueue(qe, 1);
    enqueue(qe, 2);
    enqueue(qe, 3);
    enqueue(qe, 4);
    enqueue(qe, 5);

    // Dequeue
    dequeue(qe);
    dequeue(qe);

    printQueue(qe);

    enqueue(qe, 6);
    enqueue(qe, 7);

    printQueue(qe);

    dequeue(qe);
    dequeue(qe);

    printQueue(qe);

    enqueue(qe, 8);
    enqueue(qe, 9);
    enqueue(qe, 10);
    enqueue(qe, 11);

    printQueue(qe);

    dequeue(qe);
    dequeue(qe);
    dequeue(qe);

    printQueue(qe);

    // Peek
    peek(qe);

    printQueue(qe);

    return 0;
}