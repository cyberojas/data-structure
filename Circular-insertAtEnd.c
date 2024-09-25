#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of a circular linked list
void insertNode(struct Node** head, int value) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty, make the new node point to itself (circular)
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        struct Node* temp = *head;

        // Traverse to the last node (which points to the head)
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Link the last node to the new node
        temp->next = newNode;
        // Make the new node point to the head (circular behavior)
        newNode->next = *head;
    }
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    
    // Traverse and print each node until we circle back to the head
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(back to head)\n");
}

int main() {
    struct Node* head = NULL;  // Initialize the head of the circular linked list

    // Insert nodes into the list
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);

    // Display the circular linked list
    displayList(head);

    // Insert another node
    insertNode(&head, 40);
    displayList(head);

    return 0;
}
