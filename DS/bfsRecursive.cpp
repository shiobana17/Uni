// Program to implement BFS using recursion in C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node in the graph
typedef struct Node {
    int data;
    struct Node** neighbors;
    int neighborCount;
    bool visited;
} Node;

// Function to create a new graph node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->neighbors = NULL;
    newNode->neighborCount = 0;
    newNode->visited = false;
    return newNode;
}

// Recursive BFS function - rear is now a pointer
void bfsRecursive(Node** queue, int front, int* rear) {
    if (front > *rear) {
        return; // Base case: queue is empty
    }
    
    Node* currentNode = queue[front];
    printf("%d ", currentNode->data);
    
    // Enqueue all unvisited neighbors
    for (int i = 0; i < currentNode->neighborCount; i++) {
        Node* neighbor = currentNode->neighbors[i];
        if (!neighbor->visited) {
            queue[++(*rear)] = neighbor;
            neighbor->visited = true;
        }
    }
    
    // Recursive call for the next node in the queue
    bfsRecursive(queue, front + 1, rear);
}

int main() {
    int n, e;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    // Allocate nodes
    Node** nodes = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(i);
    }
    
    // Input edges
    printf("Enter number of edges: ");
    scanf("%d", &e);
    
    // Temporary adjacency counters
    int* counts = (int*)calloc(n, sizeof(int));
    int (*edges)[2] = (int(*)[2])malloc(e * sizeof(*edges));
    int u, v;
    
    for (int i = 0; i < e; i++) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        edges[i][0] = u;
        edges[i][1] = v;
        counts[u]++;
        counts[v]++;
    }
    
    // Allocate adjacency lists
    for (int i = 0; i < n; i++) {
        nodes[i]->neighbors = (Node**)malloc(counts[i] * sizeof(Node*));
        nodes[i]->neighborCount = 0;
    }
    
    // Fill adjacency lists
    for (int i = 0; i < e; i++) {
        u = edges[i][0];
        v = edges[i][1];
        nodes[u]->neighbors[nodes[u]->neighborCount++] = nodes[v];
        nodes[v]->neighbors[nodes[v]->neighborCount++] = nodes[u];
    }
    
    free(edges);
    free(counts);
    
    int start;
    printf("Enter starting node for BFS: ");
    scanf("%d", &start);
    
    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = -1;
    
    queue[++rear] = nodes[start];
    nodes[start]->visited = true;  // Mark starting node as visited
    
    printf("BFS traversal: ");
    bfsRecursive(queue, front, &rear);  // Pass rear by reference
    printf("\n");
    
    // Cleanup
    for (int i = 0; i < n; i++) {
        free(nodes[i]->neighbors);
        free(nodes[i]);
    }
    free(nodes);
    free(queue);
    
    return 0;
}