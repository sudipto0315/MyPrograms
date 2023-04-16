#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t Node_t;
typedef struct Node_t *Node;
typedef void *Object;
typedef Node List;

struct Node_t {
    Object data;
    Node next;
};

Node newNode(Object data, Node next) {
    Node node = (Node) calloc(1, sizeof (Node_t));
    node->data = data;
    node->next = next;
    return node;
}

void addFirst(Node *pnode, Object data) {
    *pnode = newNode(data, *pnode);
}

void printList(Node node) {
    //for (; node; node = node->next)
    //    printf("%s -> ", node->data);
    while (node != NULL) {
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node list = NULL;
    addFirst(&list, "Sumit");
    addFirst(&list, "Shripad");
    addFirst(&list, "Atul");

    // int i = 5;
    // addFirst(&list, &i);
    printList(list);
}