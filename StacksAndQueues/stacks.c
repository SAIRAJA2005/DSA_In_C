#include <stdio.h>

#define SIZE 100  // Maximum size of the stack

int stack[SIZE]; // Array to store stack elements
int top = -1;    // Initialize top to -1, indicating the stack is empty

// Push operation: Adds an element to the top of the stack
void push(int x) {
    if (top == SIZE - 1) {
        // Stack is full, can't push more elements
        printf("Stack Overflow\n");
    } else {
        // Increment top and insert the element
        stack[++top] = x;
        printf("%d pushed to stack.\n", x);
    }
}

// Pop operation: Removes and returns the top element from the stack
int pop() {
    if (top == -1) {
        // Stack is empty, nothing to pop
        printf("Stack Underflow\n");
        return -1; // Return a default value
    } else {
        // Return the top element and decrement top
        return stack[top--];
    }
}

// Peek operation: Returns the top element without removing it
int peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

// isEmpty operation: Checks if the stack is empty
int isEmpty() {
    return top == -1;
}

// Driver Code to demonstrate stack operations
int main() {
    push(10);      // Push 10
    push(20);      // Push 20
    push(30);      // Push 30

    printf("Top element is %d\n", peek()); // Should print 30

    printf("Popped element is %d\n", pop()); // Should remove 30
    printf("Popped element is %d\n", pop()); // Should remove 20

    if (isEmpty())
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");

    return 0;
}
