#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    struct Node* lastNode = head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

void deleteNode(int data) {
    struct Node* currentNode = head;
    while (currentNode != NULL && currentNode->data != data) {
        currentNode = currentNode->next;
    }
    if (currentNode == NULL) {
        printf("Node not found.\n");
        return;
    }
    if (currentNode->prev != NULL) {
        currentNode->prev->next = currentNode->next;
    } else {
        head = currentNode->next;
    }
    if (currentNode->next != NULL) {
        currentNode->next->prev = currentNode->prev;
    }
    free(currentNode);
}

void printList() {
    struct Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtBeginning(4);
    printList();
    deleteNode(2);
    printList();
    return 0;
}