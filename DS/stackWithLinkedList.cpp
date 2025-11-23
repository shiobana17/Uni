// Program to implement stack using linked list in C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure to represent the stack
typedef struct Stack {
    Node* top;
} Stack;

// Function to create and initialize the stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL; // Initialize top to NULL indicating an empty stack
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed onto stack\n", data);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return  INT_MIN; // Indicate stack is empty
    }
    Node* temp = stack->top;
    int poppedData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedData;
}

// Function to peek at the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return INT_MIN; // Indicate stack is empty
    }
    return stack->top->data;
}

// Function to display the stack elements
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: \n");
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d \n", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    printf("Program for Stack Implementation using Linked List\n");

    Stack* stack = createStack();
    int choice, value, again;

    /* Initial push loop */
    do {
        printf("\nEnter data to be pushed onto stack: ");
        scanf("%d", &value);
        push(stack, value);

        printf("Do you want to push another element? (1 = yes, 0 = no): ");
        scanf("%d", &again);
    } while (again == 1);

    /* Menu-driven operations */
    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Terminate\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;

            case 2:
                value = pop(stack);
                if (value != INT_MIN) {
                    printf("%d popped from stack\n", value);
                }
                break;

            case 3:
                value = peek(stack);
                if (value != INT_MIN) {
                    printf("Top element is %d\n", value);
                }
                break;

            case 4:
                display(stack);
                break;

            case 5:
                printf("Program Terminated...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
