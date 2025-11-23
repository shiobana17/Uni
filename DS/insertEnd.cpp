// Program to insert a node at the end of a singly linked list in C
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode; // New head of the list
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head; // Head remains unchanged
}

// Function to traverse the linked list and print its elements
void traverseList(Node* head) {
    printf("Linked List: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    printf("Program for Inserting Node at End of Singly Linked List\n");
    Node* head = NULL; // Initialize head to NULL
    char choice;
    do {
        int value;
        printf("\nEnter data to be inserted at the end: ");
        scanf("%d", &value);
        head = insertAtEnd(head, value); // Update head after insertion
        printf("\nDo you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Traverse and print the linked list
    traverseList(head);
    return 0;
}