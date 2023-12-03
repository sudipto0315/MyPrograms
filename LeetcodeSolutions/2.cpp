#include <iostream>
#include <vector>
using namespace std;
// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int num1 = 0, num2 = 0;
    ListNode* curr = l1;
    while (curr) {
        num1 = num1 * 10 + curr->val;
        curr = curr->next;
    }
    curr = l2;
    while (curr) {
        num2 = num2 * 10 + curr->val;
        curr = curr->next;
    }
    int sum = num1 + num2;
    ListNode* result = nullptr;
    ListNode* tail = nullptr;
    while (sum > 0) {
        int digit = sum % 10;
        ListNode* newNode = new ListNode(digit);
        if (result == nullptr) {
            result = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        sum /= 10;
    }
    // If sum is zero, create a new node with value 0
    if (result == nullptr) {
        result = new ListNode(0);
    }
    return result;
}
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const vector<int>& values) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Solution solution;

    // Example usage
    vector<int> values1 = {1,2};
    vector<int> values2 = {1,2,3};

    ListNode* l1 = createLinkedList(values1);
    ListNode* l2 = createLinkedList(values2);

    cout << "Input Linked List 1: ";
    printLinkedList(l1);

    cout << "Input Linked List 2: ";
    printLinkedList(l2);

    // Call the addTwoNumbers function
    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "Result Linked List: ";
    printLinkedList(result);

    // Don't forget to free the memory allocated for the linked lists

    return 0;
}
