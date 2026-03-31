#include<stdio.h>

int arr[200];
int top = -1;
int size = 5;

void push(int value) {
    if (top == size - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    arr[top] = value;
    printf("Value %d pushed to the stack.\n", value);
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int y = arr[top];
    top--;
    printf("Value %d popped from the stack.\n", y);
    return y;
}

void printStack() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\nChoose an option:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(value);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            printStack();
        } else if (choice == 4) {
            printf("Exiting...\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
