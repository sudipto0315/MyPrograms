#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL){
            return 0;
        }
        if(root->val<low){
            return rangeSumBST(root->right,low,high);
        }
        if(root->val>high){
            return rangeSumBST(root->left,low,high);
        }
        return root->val+rangeSumBST(root->right,low,high)+rangeSumBST(root->left,low,high);
    }
};
int main() {
    // Construct the BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    // Create a Solution object
    Solution s;

    // Call the rangeSumBST method with the BST and the range
    int sum = s.rangeSumBST(root, 7, 15);

    // Print the result
    cout << "The sum of values of all nodes in the BST that are within the range [7, 15] is: " << sum << endl;

    return 0;
}