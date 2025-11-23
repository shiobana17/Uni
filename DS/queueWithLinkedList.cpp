// Program to implement queue using a linked list in C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure to represent the queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create and initialize the queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL; // Initialize front to NULL indicating an empty queue
    queue->rear = NULL;  // Initialize rear to NULL indicating an empty queue
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Function to enqueue an element into the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode; // Set front to new node when the first element is enqueued
    } else {
        queue->rear->next = newNode; // Link the old rear to the new node
    }
    queue->rear = newNode; // Update rear to the new node
    printf("%d enqueued into queue\n", data);
}

// Function to dequeue an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from empty queue\n");
        return INT_MIN; // Indicate queue is empty
    }
    Node* temp = queue->front;
    int dequeuedData = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL; // If the queue is now empty, update rear to NULL
    }
    free(temp);
    return dequeuedData;
}

// Function to display the queue elements
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: \n");
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d \n", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    printf("Program to Implement Queue using Linked List in C\n");
    Queue* queue = createQueue();
    int choice, value, again;

    /* Initial enqueue loop */
    do {
        printf("\nEnter data to be enqueued: ");
        scanf("%d", &value);
        enqueue(queue, value);

        printf("Do you want to enqueue another element? (1 = yes, 0 = no): ");
        scanf("%d", &again);
    } while (again == 1);

    /* Menu-driven operations */
    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Terminate\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;

            case 2:
                value = dequeue(queue);
                if (value != INT_MIN) {
                    printf("%d dequeued from queue\n", value);
                }
                break;

            case 3:
                display(queue);
                break;

            case 4:
                printf("Program Terminated...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}