#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>s1=getLeafs(root1);
        vector<int>s2=getLeafs(root2);
        if(s1.size()!=s2.size()){
            return false;
        }
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                return false;
            }
        }
        return true;
    }
    vector<int>getLeafs(TreeNode* root){
        vector<int>result;
        dfs(root,result);
        return result;
    }
    void dfs(TreeNode* root,vector<int>&result){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            result.push_back(root->val);
        }
        dfs(root->left,result);
        dfs(root->right,result);
    }
};
int main(){
    Solution s;

    // Construct the first binary tree
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);

    // Construct the second binary tree
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);

    // Call the function with the binary trees
    // Replace 'functionName' with the actual function name
    cout<<s.leafSimilar(root1, root2)<<endl;
    return 0;
}