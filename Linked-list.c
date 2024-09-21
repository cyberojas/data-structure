#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;  // If the list is empty, make the new node the head
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;  // Traverse to the end of the list
        }
        temp->next = newNode;  // Link the last node to the new node
    }
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node with a given value
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;



    // Search for the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not found in the list
    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    // Unlink the node from the list and free its memory
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

int main() {
    struct Node* head = NULL;  // Initialize the head of the list

    // Insert nodes into the list
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);

    // Display the list
    displayList(head);

    // Delete a node from the list
    deleteNode(&head, 20);
    displayList(head);

    // Try to delete a node not in the list
    deleteNode(&head, 40);
    displayList(head);

    return 0;
}
