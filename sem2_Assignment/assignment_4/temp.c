#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, struct Node** tail, struct Node* node) {
    if (*head == NULL) {
        *head = node;
        *tail = node;
    } else {
        (*tail)->next = node;
        node->prev = *tail;
        *tail = node;
    }
}

// Function to merge two sorted doubly linked lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* mergedHead = NULL;
    struct Node* mergedTail = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            insertEnd(&mergedHead, &mergedTail, newNode(head1->data));
            head1 = head1->next;
        } else {
            insertEnd(&mergedHead, &mergedTail, newNode(head2->data));
            head2 = head2->next;
        }
    }

    while (head1 != NULL) {
        insertEnd(&mergedHead, &mergedTail, newNode(head1->data));
        head1 = head1->next;
    }

    while (head2 != NULL) {
        insertEnd(&mergedHead, &mergedTail, newNode(head2->data));
        head2 = head2->next;
    }

    return mergedHead;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to test the program
int main() {
    // Create two sorted doubly linked lists
    struct Node* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->prev = head1;
    head1->next->next = newNode(5);
    head1->next->next->prev = head1->next;

    struct Node* head2 = newNode(2);
    head2->next = newNode(4);
    head2->next->prev = head2;
    head2->next->next = newNode(6);
    head2->next->next->prev = head2->next;

    // Merge the two lists
    struct Node* mergedHead = mergeLists(head1, head2);

    // Print the merged list
    printList(mergedHead);

    return 0;
}