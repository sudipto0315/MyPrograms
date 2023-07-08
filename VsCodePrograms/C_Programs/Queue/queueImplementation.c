#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isFull(Queue *queue)
{
    return (queue->rear == MAX_SIZE - 1);
}

int isEmpty(Queue *queue)
{
    return (queue->front == -1 || queue->front > queue->rear);
}

void enqueue(Queue *queue, int element)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }

    queue->rear++;
    queue->data[queue->rear] = element;

    if (queue->front == -1)
    {
        queue->front = 0; // Set front when enqueueing the first element
    }
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    int element = queue->data[queue->front];
    queue->front++;

    if (queue->front > queue->rear)
    {
        // Reset front and rear when the queue becomes empty
        queue->front = -1;
        queue->rear = -1;
    }

    return element;
}

void displayQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main()
{
    Queue queue;
    initQueue(&queue);

    int choice, element;

    while (1)
    {
        printf("\nQueue Operations:\n");
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
