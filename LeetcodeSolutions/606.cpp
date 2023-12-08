#include <iostream>
#include <string>
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
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string s = to_string(t->val);
        if (t->left || t->right) s += "(" + tree2str(t->left) + ")";
        if (t->right) s += "(" + tree2str(t->right) + ")";
        return s;
    }
};

int main() {
    // Example usage:
    // Construct a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    // Create a Solution object
    Solution solution;

    // Convert the binary tree to a string representation
    string result1 = solution.tree2str(root);

    // Output the result
    cout << result1 << endl;

    // Don't forget to free the allocated memory to avoid memory leaks
    // (This is just for illustration, in practice, you might use smart pointers or another memory management strategy)
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(3);

    string result2 = solution.tree2str(root);
    cout << result2 << endl;

    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
