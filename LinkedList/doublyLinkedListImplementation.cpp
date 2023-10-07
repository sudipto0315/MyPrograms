#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

typedef Node* List;

Node* newNode(int data, Node* next, Node* prev) {
    Node* node = new Node;
    node->data = data;
    node->next = next;
    node->prev = prev;
    return node;
}

void insertAtStart(List* pnode, int data) {
    Node* new_node = newNode(data, *pnode, nullptr);
    if (*pnode != nullptr) {
        (*pnode)->prev = new_node;
    }
    *pnode = new_node;
}

void insertAtLast(List* pnode, int data) {
    if (*pnode == nullptr) {
        insertAtStart(pnode, data);
    }

    Node* node = *pnode;
    while (node->next) {
        node = node->next;
    }

    node->next = newNode(data, nullptr, node);
}

int insertAtIndex(List* pnode, int data, int index) {
    if (index == 0) {
        insertAtStart(pnode, data);
        return -1;
    }
    Node* node = *pnode;
    index--;
    while (index > 0 && node != nullptr) {
        node = node->next;
        index--;
    }
    if (node == nullptr) {
        return -1;
    }

    if (node->next == nullptr) {
        insertAtLast(pnode, data);
        return -1;
    }
    Node* new_node = newNode(data, node->next, node);
    node->next->prev = new_node;
    node->next = new_node;
    return -1;
}

int removeFirst(List* pnode) {
    if (*pnode == nullptr) {
        return -1;
    }

    Node* node = *pnode;
    if (node->next == nullptr) {
        *pnode = nullptr;
        int data = node->data;
        delete node;
        return data;
    }

    node->next->prev = nullptr;
    *pnode = node->next;
    int data = node->data;
    delete node;
    return data;
}

int removeLast(List* pnode) {
    Node* node = *pnode;
    if (node == nullptr || node->next == nullptr) {
        return removeFirst(pnode);
    }

    while (node->next->next) {
        node = node->next;
    }

    Node* temp = node->next;
    node->next = nullptr;
    int data = temp->data;
    delete temp;
    return data;
}

int removeIndex(List* pnode, int index) {
    if (index == 0) {
        return removeFirst(pnode);
    }

    Node* node = *pnode;
    index--;

    while (node && index) {
        node = node->next;
        index--;
    }

    if (node == nullptr || node->next == nullptr) {
        return -1;
    }

    if (node->next->next == nullptr) {
        return removeLast(pnode);
    }

    Node* temp = node->next;
    temp->next->prev = node;
    node->next = temp->next;
    int data = temp->data;
    delete temp;
    return data;
}

void display(Node* node) {
    Node* end;
    cout << "\nIn Forward Direction \n";
    while (node != nullptr) {
        cout << " " << node->data << " ";
        end = node;
        node = node->next;
    }

    cout << "\nIn Backward Direction \n";
    while (end != nullptr) {
        cout << " " << end->data << " ";
        end = end->prev;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    int data, index, deletedElement;
    int n = 0, list_Len = 0;
    cout << "\t*** Welcome to Doubly Linked List Menu Based Program *** \n";
    cout << "Enter the length of the Doubly linked list: ";
    cin >> list_Len;
    cout << "Enter the elements:\n";
    for (int i = 1; i <= list_Len; i++) {
        cout << "Enter element " << i << " : ";
        cin >> data;
        insertAtStart(&head, data);
    }
    cout << "\n";
    cout << "\t*** Following Are The Operations You Can Perform On The Linked List *** \n"
         << "Press 1: To add Number in the beginning of the list.\n"
         << "Press 2: To add Number at the nth position of the list.\n"
         << "Press 3: To add Number at the last of the list.\n"
         << "Press 4: To remove Number in the beginning of the list.\n"
         << "Press 5: To remove Number at the nth position of the list.\n"
         << "Press 6: To remove Number at the last of the list.\n"
         << "Press 8: To print the list.\n"
         << "Press 0: To exit from the Program.\n\n";
    while (1) {
        cout << "Please Enter Your Choice:";
        cin >> n;
        if (n == 0) {
            cout << "\tThank You\n";
            cout << "\tHave a nice day\n";
            exit(0);
        } else if (n == 1) {
            cout << "Please Enter the Number which you want to add in the beginning:";
            cin >> data;
            insertAtStart(&head, data);
        } else if (n == 2) {
            cout << "Please Enter the position at which you want to add a number:";
            cin >> index;
            cout << "Please Enter the Number which you want to add at the " << index << " position of the list:";
            cin >> data;
            insertAtIndex(&head, data, index);
        } else if (n == 3) {
            cout << "Please Enter the Number which you want to add at the last:";
            cin >> data;
            insertAtLast(&head, data);
        } else if (n == 4) {
            deletedElement = removeFirst(&head);
            cout << "The removed value is: " << deletedElement << endl;
        } else if (n == 5) {
            cout << "Please Enter the position at which you want to remove a number:";
            cin >> index;
            deletedElement = removeIndex(&head, index);
            cout << "The removed value is: " << deletedElement << endl;
        } else if (n == 6) {
            deletedElement = removeLast(&head);
            cout << "The removed value is: " << deletedElement << endl;
        } else if (n == 8) {
            display(head);
        } else {
            cout << "You Have Entered a Wrong choice!!!\n"
                 << "Please Try Again.";
        }
        cin.ignore();
    }
    return 0;
}
