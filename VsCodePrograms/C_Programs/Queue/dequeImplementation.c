#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Deque;

void initDeque(Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isFull(Deque* deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

int isEmpty(Deque* deque) {
    return (deque->front == -1);
}

void enqueueFront(Deque* deque, int element) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot enqueue element.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    deque->data[deque->front] = element;
}

void enqueueRear(Deque* deque, int element) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot enqueue element.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }

    deque->data[deque->rear] = element;
}

int dequeueFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot dequeue element.\n");
        return -1;
    }

    int element = deque->data[deque->front];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }

    return element;
}

int dequeueRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot dequeue element.\n");
        return -1;
    }

    int element = deque->data[deque->rear];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }

    return element;
}

void displayDeque(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");

    int i = deque->front;
    while (i != deque->rear) {
        printf("%d ", deque->data[i]);
        i = (i + 1) % MAX_SIZE;
    }

    printf("%d\n", deque->data[i]);
}

int main() {
    Deque deque;
    initDeque(&deque);

    int choice, element;

    while (1) {
        printf("\nDeque Operations:\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue at the front: ");
                scanf("%d", &element);
                enqueueFront(&deque, element);
                break;
            case 2:
                printf("Enter the element to enqueue at the rear: ");
                scanf("%d", &element);
                enqueueRear(&deque, element);
                break;
            case 3:
                element = dequeueFront(&deque);
                if (element != -1) {
                    printf("Dequeued element from the front: %d\n", element);
                }
                break;
            case 4:
                element = dequeueRear(&deque);
                if (element != -1) {
                    printf("Dequeued element from the rear: %d\n", element);
                }
                break;
            case 5:
                displayDeque(&deque);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
