#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct
{
    int data[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isFull(CircularQueue *queue)
{
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

int isEmpty(CircularQueue *queue)
{
    return (queue->front == -1);
}

void enqueue(CircularQueue *queue, int element)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }

    if (isEmpty(queue))
    {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = element;
}

int dequeue(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    int element = queue->data[queue->front];

    if (queue->front == queue->rear)
    {
        // Reset front and rear when the queue becomes empty
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return element;
}

void displayQueue(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    int i = queue->front;
    while (i != queue->rear)
    {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    }

    printf("%d\n", queue->data[i]);
}

int main()
{
    CircularQueue queue;
    initQueue(&queue);

    int choice, element;

    while (1)
    {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &element);
            enqueue(&queue, element);
            break;
        case 2:
            element = dequeue(&queue);
            if (element != -1)
            {
                printf("Dequeued element: %d\n", element);
            }
            break;
        case 3:
            displayQueue(&queue);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
