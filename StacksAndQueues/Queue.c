#include <stdio.h>

#define SIZE 100  // Maximum size of the queue

int queue[SIZE]; // Array to store queue elements
int front = -1;  // Index of the front element
int rear = -1;   // Index of the rear element

// Enqueue operation: Adds an element to the rear of the queue
void enqueue(int x) {
    if (rear == SIZE - 1) {
        // Queue is full
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0; // Set front to 0 on first insertion
        queue[++rear] = x;          // Insert element and move rear
        printf("%d enqueued to queue.\n", x);
    }
}

// Dequeue operation: Removes and returns the front element of the queue
int dequeue() {
    if (front == -1 || front > rear) {
        // Queue is empty
        printf("Queue Underflow\n");
        return -1;
    } else {
        // Return the front element and move front
        return queue[front++];
    }
}

// Peek operation: Returns the front element without removing it
int peek() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return -1;
    } else {
        return queue[front];
    }
}

// isEmpty operation: Checks if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Driver Code to demonstrate queue operations
int main() {
    enqueue(10);      // Add 10
    enqueue(20);      // Add 20
    enqueue(30);      // Add 30

    printf("Front element is %d\n", peek()); // Should print 10

    printf("Dequeued element is %d\n", dequeue()); // Should remove 10
    printf("Dequeued element is %d\n", dequeue()); // Should remove 20

    if (isEmpty())
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");

    return 0;
}
