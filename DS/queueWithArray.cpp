// Program to implement queue using an array in C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 10 // Maximum size of the queue

// Structure to represent the queue
typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Function to create and initialize the queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1; // Initialize front to -1 indicating an empty queue
    queue->rear = -1;  // Initialize rear to -1 indicating an empty queue
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to enqueue an element into the queue
void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", data);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0; // Set front to 0 when the first element is enqueued
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->arr[queue->rear] = data;
    printf("%d enqueued into queue\n", data);
}

// Function to dequeue an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from empty queue\n");
        return INT_MIN;
    }
    int dequeuedData = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        // Queue has only one element, reset to empty state
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    return dequeuedData;
}

// Function to display the queue elements
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: \n");
    int i = queue->front;
    while (1) {
        printf("%d \n", queue->arr[i]);
        if (i == queue->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    printf("Program to Implement Queue using Array in C\n");
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