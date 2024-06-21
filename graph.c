#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
struct Node
{
    int vertex;
    struct Node *next;
};

// Structure to represent the graph
struct Graph
{
    int numVertices;
    struct Node *adjList[MAX_VERTICES];
};

// Function to create a new node
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with n vertices
struct Graph *createGraph(int n)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = n;

    for (int i = 0; i < n; i++)
    {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        struct Node *temp = graph->adjList[i];
        printf("Adjacency list of vertex %d\n", i);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to perform depth-first search
void DFS(struct Graph *graph, int vertex, int visited[])
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node *temp = graph->adjList[vertex];
    while (temp)
    {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex])
        {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

int main()
{
    int numVertices = 5;
    struct Graph *graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Graph representation:\n");
    printGraph(graph);

    printf("\nDepth-First Search (starting from vertex 0):\n");
    int visited[MAX_VERTICES] = {0};
    DFS(graph, 0, visited);

    return 0;
}