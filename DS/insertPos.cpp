// Program to insert a node at any position of a singly linked list
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

// Function to insert a node at a given position in the linked list
Node* insertAtPosition(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = head;
        return newNode; // New head of the list
    }
    Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position out of bounds. Inserting at the end.\n");
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
    }
    newNode->next = current->next;
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
    printf("Program for Inserting Node at Any Position of Singly Linked List\n");
    Node* head = NULL; // Initialize head to NULL
    char choice;
    do {
        int value, position;
        printf("\nEnter data to be inserted: ");
        scanf("%d", &value);
        printf("Enter position to insert the node (0-based index): ");
        scanf("%d", &position);
        head = insertAtPosition(head, value, position); // Update head after insertion
        printf("\nDo you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Traverse and print the linked list
    traverseList(head);
    return 0;
}