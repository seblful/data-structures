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

// Function to insert a new element into the heap
void insert(Heap *heap, int value)
{
    if (heap->size == heap->capacity)
    {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }
    // Insert the new element at the end
    int i = heap->size++;
    heap->array[i] = value;
    // Fix the heap property if it is violated
    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i])
    {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the maximum element from the heap
int extractMax(Heap *heap)
{
    if (heap->size == 0)
    {
        printf("Heap is empty. Cannot extract maximum element.\n");
        return -1;
    }
    // Store the root element
    int max = heap->array[0];
    // Replace the root with the last element
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    // Heapify the root
    heapify(heap, 0);
    return max;
}
// Function to print the elements of the heap
void printHeap(Heap *heap)
{
    printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

// Example usage of the heap
int main()
{
    Heap *heap = createHeap(10);
    insert(heap, 35);
    insert(heap, 33);
    insert(heap, 42);
    insert(heap, 10);
    insert(heap, 14);
    insert(heap, 19);
    insert(heap, 27);
    insert(heap, 44);
    insert(heap, 26);
    insert(heap, 31);
    printHeap(heap);
    int max = extractMax(heap);
    printf("Maximum element: %d\n", max);
    return 0;
};