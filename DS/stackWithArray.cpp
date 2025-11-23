// Program to implement stack using an array in C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 10 // Maximum size of the stack

// Structure to represent the stack
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Function to create and initialize the stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1; // Initialize top to -1 indicating an empty stack
    return stack;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", data);
        return;
    }
    stack->arr[++stack->top] = data;
    printf("%d pushed onto stack\n", data);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return INT_MIN;
    }
    return stack->arr[stack->top--];
}

// Function to peek at the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return INT_MIN;
    }
    return stack->arr[stack->top];
}

// Function to display the stack elements
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: \n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d \n", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack();
    int choice, value;
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
    free(stack); // Free allocated memory
    return 0;
}