#include <stdio.h>
#include <stdlib.h>

// Define Node structure // It is a Node type Structure
struct Node {

    int val;
    struct Node *next; //These are called structure member
};

struct Node *head = NULL; // Variable of Node structure is head pointer

// Insert a Node at the beginning of a Linked list
// Like 20->30->40; If I insert 10 at the beginning the output will be 10->20->30->40
void insertHead(int value) {
    struct Node *newNode = malloc(sizeof(struct Node)); // Using malloc function created a Node named newNode
    newNode->val = value;
    newNode->next = head;
    head = newNode;
}



// Function to insert at the tail or last position
void insertTail(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;

    if (head == NULL) { // If there is no element in the Linked List
        head = newNode;
    } else {
        struct Node *traveller = head;
        while (traveller->next != NULL) { //Finds the last element of the Last Node in the Linked List
            traveller = traveller->next;
        }
        traveller->next = newNode;
    }

}


// Function to insert after a specific value
/*void insertAfter(int oldValue, int newValue) {
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
        traveller->next = newNode;
    }
     printf("Null");
}
*/

// Function to delete the head node
void deleteHead() {
    if (head == NULL) {
        printf("The list is empty, nothing to delete!\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp); // free is used to delete Node
}

// Function to delete the tail node
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
    while (traveller->next->next != NULL) {
        traveller = traveller->next;
    }

    free(traveller->next);
    traveller->next = NULL;
}

// Function to delete a node after a specific value
/*void deleteAfter(int oldValue) {
    struct Node *traveller = head;

    while (traveller != NULL && traveller->val != oldValue) {
        traveller = traveller->next;
    }

    if (traveller == NULL || traveller->next == NULL) {
        printf("Cannot delete after %d as it doesn't exist or is the last node!\n", oldValue);
    } else {
        struct Node *temp = traveller->next;
        traveller->next = temp->next;
        free(temp);
    }
}
*/

// Function to print the linked list
void printLinkedList() {
    printf("Linked list: ");
    struct Node *traveller = head;
    while (traveller != NULL) {
        printf("%d -> ", traveller->val);
        traveller = traveller->next;
    }
    printf("Null");
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
        printf("7. Print the linked list\n");
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
        } /* else if (choice == 3) {
            printf("Enter the value after which to insert: ");
            scanf("%d", &oldValue);
            printf("Enter the new value to insert: ");
            scanf("%d", &value);
            insertAfter(oldValue, value);
        }*/
         else if (choice == 4) {
            deleteHead();
        } else if (choice == 5) {
            deleteTail();
        } /*else if (choice == 6) {
            printf("Enter the value after which to delete: ");
            scanf("%d", &oldValue);
            deleteAfter(oldValue);
        }
        */
        else if (choice == 7) {
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
