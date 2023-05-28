#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* new_node1 = (struct Node*) malloc(sizeof(struct Node));
    struct Node* new_node2 = (struct Node*) malloc(sizeof(struct Node));
    struct Node* new_node3 = (struct Node*) malloc(sizeof(struct Node));

    struct Node* head;

    new_node1->data = 10;
    new_node1->next = new_node2;
    printf("size of node1 = %d \n", sizeof(new_node1));
    printf("size of *node1 = %d \n", sizeof(*new_node1));
    printf("node1 = %d \n", new_node1);
    printf("Address of node1.data = %d \n", &(new_node1->data));
    printf("Address of node1.next = %d \n", &(new_node1->next));
   
    new_node2->data = 20;
    new_node2->next = new_node3;
    printf("size of node2 = %d \n", sizeof(new_node2));
   
    new_node3->data = 30;
    new_node3->next = NULL;
    printf("size of node3 = %d \n", sizeof(new_node3));
   
    head = new_node1;

    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
   

    printf("\n");
    return 0;
}
