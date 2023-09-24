#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enQueue(int value) {
  if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) {
    printf("Queue is full\n");
    return;
  } else if (front == -1) {
    front = rear = 0;
    queue[rear] = value;
  } else if (rear == MAX_SIZE - 1 && front != 0) {
    rear = 0;
    queue[rear] = value;
  } else {
    rear++;
    queue[rear] = value;
  }
}

void deQueue() {
  if (front == -1) {
    printf("Queue is empty\n");
  } else if (front == rear) {
    printf("Deleted element: %d\n", queue[front]);
    front = rear = -1;
  } else if (front == MAX_SIZE - 1) {
    printf("Deleted element: %d\n", queue[front]);
    front = 0;
  } else {
    printf("Deleted element: %d\n", queue[front]);
    front++;
  }
}

void display() {
  if (front == -1) {
    printf("Queue is empty\n");
    return;
  }

  printf("Elements in Circular Queue are: \n");
  if (rear >= front) {
    for (int i = front; i <= rear; i++)
      printf("%d ", queue[i]);
  } else {
    for (int i = front; i < MAX_SIZE; i++)
      printf("%d ", queue[i]);

    for (int i = 0; i <= rear; i++)
      printf("%d ", queue[i]);
  }
  printf("\n");
}

int main() {
  int choice, value;

  while (1) {
    printf("\n\n***** CIRCULAR QUEUE MENU *****\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter the value to be enqueued: ");
        scanf("%d", &value);
        enQueue(value);
        break;
      
      case 2:
        deQueue();
        break;
      
      case 3:
        display();
        break;

      case 4:
        printf("Exiting the program\n");
        return 0;

      default:
        printf("Invalid choice\n");
    }
  }
}
