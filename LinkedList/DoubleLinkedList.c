#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert at beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
    printf("Inserted %d at the beginning.\n", value);

    /*
        Output:
        ----------------------------
        Inserted 10 at the beginning.
        Inserted 5 at the beginning.
    */
}

// 2. Insert at end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at the end (list was empty).\n", value);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at the end.\n", value);

    /*
        Output:
        ----------------------------
        Inserted 20 at the end.
        Inserted 30 at the end.
    */
}

// 3. Delete from beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;

    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);

    /*
        Output:
        ----------------------------
        Deleted 5 from the beginning.
    */
}

// 4. Delete from end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    // Traverse to the last node
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        *head = NULL;

    printf("Deleted %d from the end.\n", temp->data);
    free(temp);

    /*
        Output:
        ----------------------------
        Deleted 30 from the end.
    */
}

// 5. Delete by value
void deleteByValue(struct Node** head, int value) {
    struct Node* temp = *head;

    // Traverse to find the node
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        /*
            Output:
            ----------------------------
            Value 100 not found in the list.
        */
        return;
    }

    // If node to delete is head
    if (temp->prev == NULL)
        *head = temp->next;
    else
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted node with value %d.\n", temp->data);
    free(temp);

    /*
        Output:
        ----------------------------
        Deleted node with value 20.
    */
}

// 6. Search
void search(struct Node* head, int value) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == value) {
            printf("Value %d found at position %d.\n", value, pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Value %d not found in the list.\n", value);

    /*
        Output:
        ----------------------------
        Value 10 found at position 1.
        Value 100 not found in the list.
    */
}

// 7. Display forward
void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Forward: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        if (head->next == NULL) break; // Save last for backward
        head = head->next;
    }
    printf("NULL\n");

    /*
        Output:
        ----------------------------
        Forward: 5 <-> 10 <-> 20 <-> 30 <-> NULL
    */
}

// 8. Display backward (from last node)
void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Go to last node
    while (head->next != NULL)
        head = head->next;

    printf("Backward: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");

    /*
        Output:
        ----------------------------
        Backward: 30 <-> 20 <-> 10 <-> 5 <-> NULL
    */
}

// 9. Free the list
void freeList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Main Function
int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    displayForward(head);
    displayBackward(head);

    deleteFromBeginning(&head);
    displayForward(head);

    deleteFromEnd(&head);
    displayForward(head);

    deleteByValue(&head, 20);
    displayForward(head);

    deleteByValue(&head, 100); // not in list

    search(head, 10);
    search(head, 100);

    freeList(&head);
    return 0;
}

/*
    output:
    ----------------------------------
    Inserted 10 at the beginning.
    Inserted 5 at the beginning.

    Inserted 20 at the end.
    Inserted 30 at the end.

    Forward: 5 <-> 10 <-> 20 <-> 30 <-> NULL
    Backward: 30 <-> 20 <-> 10 <-> 5 <-> NULL

    Deleted 5 from the beginning.
    Forward: 10 <-> 20 <-> 30 <-> NULL

    Deleted 30 from the end.
    Forward: 10 <-> 20 <-> NULL

    Deleted node with value 20.
    Forward: 10 <-> NULL

    Value 100 not found in the list.
    
    Value 10 found at position 1.

    Value 100 not found in the list.
*/