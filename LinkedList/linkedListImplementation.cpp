#include <iostream>

using namespace std;

typedef struct Node_t Node_t;
typedef struct Node_t* Node;
// typedef Node List;

struct Node_t {
    int data;
    Node next;
};

Node newNode(int data, Node next) {
    Node node = new Node_t;
    node->data = data;
    node->next = next;
    return node;
}

void addFirst(Node *pnode, int data) {
    *pnode = newNode(data, *pnode);
}

void addLast(Node *pnode, int data) {
    if (*pnode == nullptr) {
        addFirst(pnode, data);
        return;
    }
    Node node = *pnode;
    while (node->next) {
        node = node->next;
    }
    node->next = newNode(data, nullptr);
}

int addAt(Node *pnode, int data, unsigned int index) {
    if (index == 0) {
        addFirst(pnode, data);
        return 1;
    }
    Node node = *pnode;
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

int removeFirst(Node *pnode) {
    if (*pnode == NULL) {
        return -1; // Return a sentinel value to indicate an error or empty list
    }
    Node node = *pnode;
    *pnode = (*pnode)->next;
    int data = node->data;
    delete node;
    return data;
}

int removeLast(Node *pnode) {
    if (*pnode == nullptr || (*pnode)->next == nullptr) {
        return removeFirst(pnode);
    }
    Node node = *pnode;
    while (node->next->next) {
        node = node->next;
    }
    int data = node->next->data;
    delete node->next;
    node->next = nullptr;
    return data;
}

int removeFrom(Node *pnode, unsigned int index) {
    if (*pnode == NULL || index == 0) {
        return removeFirst(pnode);
    }
    Node node = *pnode;
    index--;
    while (node && index) {
        node = node->next;
        index--;
    }
    if (node == NULL || node->next == NULL) {
        return -1; // Return a sentinel value to indicate an error or invalid index
    }
    Node tempNode = node->next;
    node->next = tempNode->next;
    int data = tempNode->data;
    delete tempNode;
    return data;
}

void printList(Node node) {
    cout<<"The Linked List is: ";
    while (node) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node list = NULL;
    int data;
    int choice;
    int n;
    // Initial user input to create the linked list
    cout<<"Enter the no of nodes: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>data;
        addLast(&list, data);
    }
    
    while (true) {
        cout <<endl;
        cout<<"1. Add First\n";
        cout<<"2. Add Last\n";
        cout<<"3. Add At\n";
        cout<<"4. Remove First\n";
        cout<<"5. Remove Last\n";
        cout<<"6. Remove From\n";
        cout<<"7. Print List\n";
        cout<<"8. Exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;
        cout<<endl;
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
                    cout << "The element " << data << " was Added successfully" << endl;
                } else {
                    cout << "Invalid index." << endl;
                }
                break;
            case 4:
                cout<<"The element "<<removeFirst(&list)<<" was removed !!"<<endl;
                break;
            case 5:
                cout<<"The element "<<removeLast(&list)<<" was removed !!"<<endl;
                break;
            case 6:
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
            case 7:
                printList(list);
                break;
            case 8:
                // Exit the program
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
