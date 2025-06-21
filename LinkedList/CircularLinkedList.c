#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert at beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;

        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
    printf("Inserted %d at the beginning.\n", value);

    /*
        Output:
        ------------------------------
        Inserted 10 at the beginning.
        Inserted 5 at the beginning.
    */
}

// 2. Insert at end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        printf("Inserted %d at the end (list was empty).\n", value);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;
    printf("Inserted %d at the end.\n", value);

    /*
        Output:
        ------------------------------
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
    if (temp->next == temp) {
        printf("Deleted %d (only node).\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }

    struct Node* last = *head;
    while (last->next != *head)
        last = last->next;

    last->next = temp->next;
    *head = temp->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);

    /*
        Output:
        ------------------------------
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

    if (temp->next == temp) {
        printf("Deleted %d (only node).\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }

    struct Node* prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head;
    printf("Deleted %d from the end.\n", temp->data);
    free(temp);

    /*
        Output:
        ------------------------------
        Deleted 30 from the end.
    */
}

// 5. Delete by value
void deleteByValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head, *prev = NULL;

    // Only node
    if (temp->data == value && temp->next == *head) {
        free(temp);
        *head = NULL;
        printf("Deleted node with value %d (only node).\n", value);
        return;
    }

    // Head node
    if (temp->data == value) {
        while (temp->next != *head)
            temp = temp->next;
        struct Node* del = *head;
        temp->next = (*head)->next;
        *head = (*head)->next;
        free(del);
        printf("Deleted node with value %d (was head node).\n", value);
        return;
    }

    prev = *head;
    temp = (*head)->next;
    while (temp != *head && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head) {
        printf("Value %d not found in the list.\n", value);
        /*
            Output:
            ------------------------------
            Value 100 not found in the list.
        */
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted node with value %d.\n", value);

    /*
        Output:
        ------------------------------
        Deleted node with value 20.
    */
}

// 6. Search
void search(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Value %d not found in the list.\n", value);

    /*
        Output:
        ------------------------------
        Value 15 found at position 2.
        Value 100 not found in the list.
    */
}

// 7. Display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");

    /*
        Output:
        ------------------------------
        Circular List: 5 -> 10 -> 20 -> 30 -> (head)
    */
}

// 8. Free all nodes
void freeList(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    struct Node* nextNode;
    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != *head);

    *head = NULL;
}

// Main Function
int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    display(head);

    deleteFromBeginning(&head);
    display(head);

    deleteFromEnd(&head);
    display(head);

    deleteByValue(&head, 20);
    display(head);

    deleteByValue(&head, 100); // Not in list

    search(head, 10);
    search(head, 100);

    freeList(&head);
    return 0;
}


/*
    Output:
    -----------------------------------
    Inserted 10 at the beginning.
    Inserted 5 at the beginning.

    Inserted 20 at the end.
    Inserted 30 at the end.

    Circular List: 5 -> 10 -> 20 -> 30 -> (head)

    Deleted 5 from the beginning.
    Circular List: 10 -> 20 -> 30 -> (head)

    Deleted 30 from the end.
    Circular List: 10 -> 20 -> (head)

    Deleted node with value 20.
    Circular List: 10 -> (head)

    Value 100 not found in the list.
    
    Value 10 found at position 1.
    Value 100 not found in the list.

*/