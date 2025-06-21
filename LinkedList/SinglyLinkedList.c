#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert at the beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", value);

    /*
        Output: 
        ---------------------------
        Inserted 10 at the beginning.
        Inserted 5 at the beginning.
    */
}

// 2. Insert at the end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at the end (list was empty).\n", value);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end.\n", value);

    /*
        Output:
        ---------------------------
        Inserted 20 at the end.
        Inserted 30 at the end.
    */
}

// 3. Insert after a given value
void insertAfterValue(struct Node* head, int afterValue, int newValue) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != afterValue) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", afterValue);
        return;
    }
    struct Node* newNode = createNode(newValue);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d after %d.\n", newValue, afterValue);

    /*
        Output:
        ---------------------------
        Inserted 15 after 10.
    */
}

// 4. Delete a node by value
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node itself holds the value
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Deleted node with value %d (was head node).\n", value);

        /*
            Output:
            ---------------------------
            Deleted node with value 5 (was head node).
        */
        return;
    }

    // Search for the value to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If value was not found
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);

        /*
            Output:
            ---------------------------
            Value 100 not found in the list.
        */
        return;
    }

    // Unlink and delete the node
    prev->next = temp->next;
    free(temp);
    printf("Deleted node with value %d.\n", value);

    /*
        Output:
        ---------------------------
        Deleted node with value 20.
    */
}

// 5. Search for an element
void searchNode(struct Node* head, int value) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Value %d not found in the list.\n", value);

    /*
        Output:
        ---------------------------
        Value 15 found at position 2.
        Value 100 not found in the list.
    */
}

// 6. Display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    /*
        Example Output:
        ---------------------------
        Linked List: 5 -> 10 -> 20 -> 30 -> NULL
    */
}

// 7. Free all nodes (cleanup)
void freeList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Main function to test all operations
int main() {
    struct Node* head = NULL; // Initialize empty list

    // Demonstrating all operations
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    displayList(head);

    insertAfterValue(head, 10, 15);
    displayList(head);

    deleteNode(&head, 5);
    displayList(head);

    deleteNode(&head, 20);
    displayList(head);

    searchNode(head, 15);
    searchNode(head, 100);

    freeList(&head); // Cleanup memory
    return 0;
}



/*
    program output:
    ------------------------
    Inserted 10 at the beginning.
    Inserted 5 at the beginning.
    Inserted 20 at the end.
    Inserted 30 at the end.
    Linked List: 5 -> 10 -> 20 -> 30 -> NULL
    Inserted 15 after 10.
    Linked List: 5 -> 10 -> 15 -> 20 -> 30 -> NULL
    Deleted node with value 5 (was head node).
    Linked List: 10 -> 15 -> 20 -> 30 -> NULL
    Deleted node with value 20.
    Linked List: 10 -> 15 -> 30 -> NULL
    Value 15 found at position 2.
    Value 100 not found in the list.
*/