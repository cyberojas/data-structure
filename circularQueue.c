#include <stdio.h>
#include <stdbool.h>

int queue[5];
int size_max = 10;
int front = -1;
int rear = -1;

void enqueue(int element);
void dequeue();
void viewqueue();
bool isfull();
bool isempty();

int main() {
    // Enqueue elements
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    // Dequeue an element
    dequeue();
    enqueue(99);
    // View the queue
    viewqueue();

    return 0;
}

void enqueue(int element) {
    if (isfull()) {
        printf("\nQueue is full");
    } else {
        if (front == -1) {  // First element being enqueued
            front = 0;
        }
        rear = (rear + 1) % size_max;  // Circular increment
        queue[rear] = element;
        printf("\nEnqueue %d", queue[rear]);
    }
}

void dequeue() {
    if (isempty()) {
        printf("\nQueue is empty.");
    } else {
        printf("\nDequeue %d", queue[front]);
        queue[front] = 0;

        if (front == rear) {
            // Queue becomes empty after this dequeue
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size_max;  // Circular increment
        }
    }
}

void viewqueue() {
    if (isempty()) {
        printf("\nQueue is empty.");
        return;
    }

    printf("\nQueue elements are: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % size_max;  // Circular traversal
    }
    printf("%d\n", queue[rear]);  // Print the last element
}

bool isfull() {
    return ((rear + 1) % size_max == front);  // Queue is full if rear is just before front
}

bool isempty() {
    return (front == -1);  // Queue is empty if front is -1
}
