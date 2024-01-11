#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findMax(TreeNode*root,int maxVal,int minVal){
        if(root==NULL){
            return maxVal-minVal;
        }
        maxVal=max(maxVal,root->val);
        minVal=min(minVal,root->val);
        int maxLeft=findMax(root->left,maxVal,minVal);
        int maxRight=findMax(root->right,maxVal,minVal);
        return max(maxLeft,maxRight);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return findMax(root,root->val,root->val);
    }
};
int main(){
    Solution s;
    TreeNode*root=new TreeNode(8);
    root->left=new TreeNode(3);
    root->right=new TreeNode(10);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(6);
    root->left->right->left=new TreeNode(4);
    root->left->right->right=new TreeNode(7);
    root->right->right=new TreeNode(14);
    root->right->right->left=new TreeNode(13);
    cout<<s.maxAncestorDiff(root)<<endl;
    return 0;
}