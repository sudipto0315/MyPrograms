#include<iostream>
#include<vector>
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
    int findPalindrome(TreeNode* root,vector<int>&freq){
        if(root==NULL){
            return 0;
        }
        freq[root->val]++;
        int count=0;
        if(root->left==NULL&&root->right==NULL){
            int flag=0;
            for(int i=0;i<freq.size();i++){
                if(freq[i]%2==1){
                    flag++;
                }
            }
            if(flag<=1){
                count=1;
            }
        }else{
            count+=findPalindrome(root->left,freq);
            count+=findPalindrome(root->right,freq);
        }
        freq[root->val]--;
        return count;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>freq(10);
        return findPalindrome(root,freq);
    }
};
int main(){
    Solution s;
    // root = [2,3,1,3,1,null,1]
    TreeNode* root=new TreeNode(2);
    root->left=new TreeNode(3);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(1);
    root->right->right=new TreeNode(1);
    cout<<s.pseudoPalindromicPaths(root)<<endl;
    
    // root = [2,1,1,1,3,null,null,null,null,null,1]
    root=new TreeNode(2);
    root->left=new TreeNode(1);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->left->right->right=new TreeNode(1);
    cout<<s.pseudoPalindromicPaths(root)<<endl;
    return 0;
}