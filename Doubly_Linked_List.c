
#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int val;
    struct Node *prev; // Pointer to the previous node
    struct Node *next; // Pointer to the next node
};

struct Node *head = NULL; // Head pointer for the doubly linked list

// Insert a Node at the beginning of a Doubly Linked List
void insertHead(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// Insert a Node at the end of a Doubly Linked List
void insertTail(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;

    if (head == NULL) { // If the list is empty
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node *traveller = head;
        while (traveller->next != NULL) { // Traverse to the last node
            traveller = traveller->next;
        }
        traveller->next = newNode;
        newNode->prev = traveller;
    }
}

// Insert after a specific value
void insertAfter(int oldValue, int newValue) {
    struct Node *traveller = head;

    while (traveller != NULL) {
        if (traveller->val == oldValue) {
            break;
        }
        traveller = traveller->next;
    }

    if (traveller == NULL) {
        printf("The value %d does not exist!\n", oldValue);
    } else {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->val = newValue;
        newNode->next = traveller->next;
        newNode->prev = traveller;

        if (traveller->next != NULL) {
            traveller->next->prev = newNode;
        }
        traveller->next = newNode;
    }
}

// Delete the head node
void deleteHead() {
    if (head == NULL) {
        printf("The list is empty, nothing to delete!\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
}

// Delete the tail node
void deleteTail() {
    if (head == NULL) {
        printf("The list is empty, nothing to delete!\n");
        return;
    }

    if (head->next == NULL) { // Only one node in the list
        free(head);
        head = NULL;
        return;
    }

    struct Node *traveller = head;
    while (traveller->next != NULL) { // Traverse to the last node
        traveller = traveller->next;
    }

    traveller->prev->next = NULL;
    free(traveller);
}

// Delete a node after a specific value
void deleteAfter(int oldValue) {
    struct Node *traveller = head;

    while (traveller != NULL && traveller->val != oldValue) {
        traveller = traveller->next;
    }

    if (traveller == NULL || traveller->next == NULL) {
        printf("Cannot delete after %d as it doesn't exist or is the last node!\n", oldValue);
    } else {
        struct Node *temp = traveller->next;
        traveller->next = temp->next;

        if (temp->next != NULL) {
            temp->next->prev = traveller;
        }
        free(temp);
    }
}

// Print the Doubly Linked List
void printLinkedList() {
    printf("Doubly linked list: ");
    struct Node *traveller = head;

    while (traveller != NULL) {
        printf("%d <-> ", traveller->val);
        traveller = traveller->next;
    }
    printf("Null\n");
}

// Main function to display menu and take user input
int main() {
    int choice, value, oldValue;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a value\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete after a value\n");
        printf("7. Print the doubly linked list\n");
        printf("8. Exit\n");
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the value to insert at the beginning: ");
            scanf("%d", &value);
            insertHead(value);
        } else if (choice == 2) {
            printf("Enter the value to insert at the end: ");
            scanf("%d", &value);
            insertTail(value);
        } else if (choice == 3) {
            printf("Enter the value after which to insert: ");
            scanf("%d", &oldValue);
            printf("Enter the new value to insert: ");
            scanf("%d", &value);
            insertAfter(oldValue, value);
        } else if (choice == 4) {
            deleteHead();
        } else if (choice == 5) {
            deleteTail();
        } else if (choice == 6) {
            printf("Enter the value after which to delete: ");
            scanf("%d", &oldValue);
            deleteAfter(oldValue);
        } else if (choice == 7) {
            printLinkedList();
        } else if (choice == 8) {
            printf("Exiting program. Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid choice! Please enter a number between 1 and 8.\n");
        }
    }

    return 0;
}
