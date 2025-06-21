#include <stdio.h>
#include <ctype.h>   // for isalpha() and isdigit()
#include <string.h>  // for strlen()

#define SIZE 100

char stack[SIZE];
int top = -1;

// Function to push element onto the stack
void push(char ch) {
    stack[++top] = ch;
}

// Function to pop element from the stack
char pop() {
    return stack[top--];
}

// Function to get the top element of the stack
char peek() {
    return stack[top];
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Main function to convert infix to postfix
void infixToPostfix(char infix[]) {
    char postfix[SIZE];
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        // If operand, add to postfix output
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '(' from stack
        }
        // If operator
        else {
            while (!isEmpty() && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // null terminate the result

    printf("Postfix Expression: %s\n", postfix);
}

// Driver Code
int main() {
    char infix[SIZE];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;

    /*
        Output:
        -------------------------
        Enter Infix Expression: A+B*C
        Postfix Expression: ABC*+
        
    */
}
