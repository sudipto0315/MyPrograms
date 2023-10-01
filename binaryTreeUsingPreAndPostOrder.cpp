#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* constructTreeUtil(vector<int>& pre, vector<int>& post, int& preIndex, int l, int h, int size) {
    if (preIndex >= size || l > h)
        return NULL;

    Node* root = newNode(pre[preIndex]);
    preIndex++;

    if (l == h)
        return root;

    int i;
    for (i = l; i <= h; ++i)
        if (pre[preIndex] == post[i])
            break;

    if (i <= h) {
        root->left = constructTreeUtil(pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil(pre, post, preIndex, i + 1, h - 1, size);
    }

    return root;
}

Node* constructTree(vector<int>& pre, vector<int>& post, int size) {
    int preIndex = 0;
    return constructTreeUtil(pre, post, preIndex, 0, size - 1, size);
}

void printInorder(Node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> pre(n), post(n);

    cout << "Enter the elements of preorder traversal:\n";
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }

    cout << "Enter the elements of postorder traversal:\n";
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }

    Node* root = constructTree(pre, post, n);

    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);
    cout<<endl;
    return 0;
}
