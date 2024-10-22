#include<stdio.h>
#include<stdbool.h>

int queue[5];        // Define the queue array
int size_max = 5;    // Maximum size of the queue
int front = -1;      // Front index of the queue
int rear = -1;       // Rear index of the queue

void enqueue(int element);
void dequeue();
int getfront();
int getrear();
void viewqueue();

int main() {
    front = -1;
    rear = -1;

    // Enqueue elements
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); // Queue is full after this

    // Dequeue an element
    dequeue();
    enqueue(99); // This should fail as queue is full after dequeuing just one element


    // View the entire queue
    viewqueue();

    return 0;
}


void enqueue(int element) {
    if (rear == size_max - 1) {  // Check if the queue is full
        printf("\nQueue is full");
    } else {
        if (front == -1) {       // If the queue is empty, set front to 0
            front = 0;
        }
        rear++;                  // Increment rear to add a new element
        queue[rear] = element;
        printf("\nEnqueue %d", queue[rear]);
    }
}


void dequeue() {
    if (front == -1) {  // Check if the queue is empty
        printf("\nQueue is empty..");
    } else {
        printf("\nDequeue %d", queue[front]);
        queue[front] = 0;  // Optional: Reset the dequeued position to 0

        front++;  // Move front to the next element

    }
}




// Function to display the elements of the queue
void viewqueue() {
    if (front == -1) {
        printf("\nQueue is empty.");
        return;
    }

    printf("\nQueue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
