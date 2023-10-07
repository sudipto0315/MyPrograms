#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* List;

Node* newNode(int data, Node* next) {
    Node* node = new Node;
    node->data = data;
    node->next = next;
    return node;
}

void addFirst(List* pnode, int data) {
    *pnode = newNode(data, *pnode);
}

void addLast(List* pnode, int data) {
    if (*pnode == nullptr) {
        addFirst(pnode, data);
        return;
    }
    Node* node = *pnode;
    while (node->next) {
        node = node->next;
    }
    node->next = newNode(data, nullptr);
}

int addAt(List* pnode, int data, unsigned int index) {
    if (index == 0) {
        addFirst(pnode, data);
        return 1;
    }
    Node* node = *pnode;
    index--;
    while (index > 0 && node != nullptr) {
        index--;
        node = node->next;
    }
    if (node == nullptr) {
        return 0;
    }
    node->next = newNode(data, node->next);
    return 1;
}

int removeFirst(List* pnode) {
    if (*pnode == nullptr) {
        return -1; // Return a sentinel value to indicate an error or empty list
    }
    Node* node = *pnode;
    *pnode = (*pnode)->next;
    int data = node->data;
    delete node;
    return data;
}

int removeLast(List* pnode) {
    if (*pnode == nullptr || (*pnode)->next == nullptr) {
        return removeFirst(pnode);
    }
    Node* node = *pnode;
    while (node->next->next) {
        node = node->next;
    }
    int data = node->next->data;
    delete node->next;
    node->next = nullptr;
    return data;
}

int removeFrom(List* pnode, unsigned int index) {
    if (*pnode == nullptr || index == 0) {
        return removeFirst(pnode);
    }
    Node* node = *pnode;
    index--;
    while (node && index) {
        node = node->next;
        index--;
    }
    if (node == nullptr || node->next == nullptr) {
        return -1; // Return a sentinel value to indicate an error or invalid index
    }
    Node* tempNode = node->next;
    node->next = tempNode->next;
    int data = tempNode->data;
    delete tempNode;
    return data;
}

void printList(Node* node) {
    while (node) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* list = nullptr;
    int data;
    int choice;

    // Initial user input to create the linked list
    while (true) {
        cout << "Enter an integer to add to the initial linked list (0 to finish): ";
        cin >> data;
        if (data == 0) {
            break;
        }
        addLast(&list, data);
    }

    while (true) {
        cout << "1. Add First\n2. Add Last\n3. Add At\n4. Remove From\n5. Print List\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                addFirst(&list, data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                addLast(&list, data);
                break;
            case 3:
                unsigned int index;
                cout << "Enter index: ";
                cin >> index;
                cout << "Enter data: ";
                cin >> data;
                if (addAt(&list, data, index)) {
                    cout << "Added successfully." << endl;
                } else {
                    cout << "Invalid index." << endl;
                }
                break;
            case 4:
                unsigned int removeIndex;
                cout << "Enter index to remove: ";
                cin >> removeIndex;
                data = removeFrom(&list, removeIndex);
                if (data != -1) {
                    cout << "Removed: " << data << " from index " << removeIndex << endl;
                } else {
                    cout << "Invalid index." << endl;
                }
                break;
            case 5:
                printList(list);
                break;
            case 6:
                // Exit the program
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
