#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int *array;
    int size;
    int capacity;
} Heap;

// Function to create heap
Heap *createHeap(int capacity)
{
    Heap *newHeap = (Heap *)malloc(sizeof(Heap));
    newHeap->array = (int *)malloc(sizeof(int) * capacity);
    newHeap->size = 0;
    newHeap->capacity = capacity;

    return newHeap;
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
};

// Function to heapify a subtree rooted at index i
void heapify(Heap *heap, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // Check if the left child is larger than the root
    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;
    // Check if the right child is larger than the largest so far
    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;
    // If the largest is not the root, swap the root with the largest
    if (largest != i)
    {
        swap(&heap->array[i], &heap->array[largest]);
        heapify(heap, largest);
    }
}

int main()
{

    return 0;
}