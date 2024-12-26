#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define maximum size of the circular queue

char queue[MAX];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    return ((rear + 1) % MAX == front);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element into the queue
void insert(char element) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %c as the queue is full.\n", element);
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        queue[rear] = element;
        printf("Inserted %c into the queue.\n", element);
    }
}

// Function to delete an element from the queue
void delete() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot delete as the queue is empty.\n");
    } else {
        printf("Deleted %c from the queue.\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

// Function to display the contents of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = front; i != rear; i = (i + 1) % MAX) {
            printf("%c ", queue[i]);
        }
        printf("%c\n", queue[rear]);
    }
}

int main() {
    int choice;
    char element;

    do {
        printf("\n-- Circular Queue Menu --\n");
        printf("1. Insert an element onto circular queue\n");
        printf("2. Delete an element from the circular queue\n");
        printf("3. demonstrate overflow and underflow situations \n");
        printf("4. display the status of the cicular queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf(" %c", &element);
                insert(element);
                break;
            case 2:
                delete();
                break;
            case 3:
                if (isFull())
                	printf("Queue is in Overflow condition\n");
                else if (isEmpty()) 
                	printf("Queue is in underflow condition\n");
                else
                	printf("Queue is neither full nor empty.\n");
                break;
            case 4:
            	display();
                break;
            case 5:
                printf("exiting.....\n");
                break;
            default:
            	printf("Invalid choice! Please try again\n");
        }
    }while(choice != 5);
    return 0;
}
