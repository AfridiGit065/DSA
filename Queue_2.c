#include <stdio.h>

int queue[5];
int front = -1;
int rear = -1;
int size = 5;


void enqueue(int value) {
    if ((rear + 1 == size && front == 0) || (rear + 1 == front)) {
        printf("Queue Overflow. Cannot enqueue %d.\n", value);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    if (rear == size - 1) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
    printf("Value %d enqueued to the queue.\n", value);
}


int dequeue() {
    if (front == -1) {
        printf("Queue Underflow. No elements to dequeue.\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }
    printf("Value %d dequeued from the queue.\n", value);
    return value;
}


void printQueue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        if (i == size - 1) {
            i = 0;
        } else {
            i++;
        }
    }
    printf("\n");
}

int main() {
    int choice = 0;
    int value;

    while (choice != 4) {
        printf("\nChoose an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            printQueue();
        } else if (choice == 4) {
            printf("Exiting...\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

