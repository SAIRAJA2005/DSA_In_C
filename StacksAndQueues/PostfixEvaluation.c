#include <stdio.h>
#include <ctype.h>   // for isdigit()
#include <stdlib.h>  // for atoi()
#include <string.h>  // for strlen()

#define SIZE 100

int stack[SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int val) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = val;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char expr[]) {
    int i;
    char ch;

    for (i = 0; expr[i] != '\0'; i++) {
        ch = expr[i];

        // Skip spaces
        if (ch == ' ' || ch == '\n')
            continue;

        // If digit, convert to number and push to stack
        if (isdigit(ch)) {
            int num = 0;

            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--; // Adjust i back after overshooting
            push(num);
        }
        // If operator, pop two elements and apply operation
        else {
            int val2 = pop();
            int val1 = pop();
            int result;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/':
                    if (val2 == 0) {
                        printf("Division by zero error!\n");
                        exit(1);
                    }
                    result = val1 / val2;
                    break;
                case '%':
                    if (val2 == 0) {
                        printf("Modulo by zero error!\n");
                        exit(1);
                    }
                    result = val1 % val2;
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }

            push(result);
        }
    }

    // Final result is on top
    return pop();
}

// Driver Code
int main() {
    char postfixExpr[SIZE];

    printf("Enter Postfix Expression (space-separated, e.g., 5 3 2 * +):\n");
    fgets(postfixExpr, SIZE, stdin);

    // Remove newline if present
    size_t len = strlen(postfixExpr);
    if (postfixExpr[len - 1] == '\n') {
        postfixExpr[len - 1] = '\0';
    }

    int result = evaluatePostfix(postfixExpr);
    printf("Evaluated Result: %d\n", result);

    return 0;
}

/*
    Output:
    --------------------------------
    
*/