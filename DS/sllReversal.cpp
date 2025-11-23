// Program to reverse a singly linked list in C
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

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    return prev; // New head of the reversed list
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
    printf("Program to Reverse a Singly Linked List\n");
    // Create nodes
    Node* head = NULL; // Initialize head to NULL
    char choice;
    do{
        int value;
        printf("\nEnter data to be entered: ");
        scanf("%d", &value);
        Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        printf("\nDo you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
        
    // Traverse and print the original linked list
    printf("\nOriginal ");
    traverseList(head);

    // Reverse the linked list
    head = reverseList(head);

    // Traverse and print the reversed linked list
    printf("\nReversed ");
    traverseList(head);
    
    return 0;
}