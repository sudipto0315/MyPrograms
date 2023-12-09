#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
    
    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (node == NULL)
            return;

        inorderHelper(node->left, result);
        result.push_back(node->val);
        inorderHelper(node->right, result);
    }
};

int main() {
    // Example usage of the Solution class
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    // Print the result
    cout << "Inorder Traversal: ";
    for (int value : result) {
        cout << value << " ";
    }
    cout << endl;

    // Clean up the dynamically allocated memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
