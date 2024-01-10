#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>graph;
        int maxNode=dfs(root,graph);
        if (start>maxNode||graph.find(start)==graph.end()){
            return 0;
        }
        int time=bfs(graph,start,maxNode);
        return time;
    }
    int dfs(TreeNode*root,unordered_map<int,vector<int>>&graph){
        if(root==NULL){
            return 0;
        }
        int maxNode=root->val;
        if(root->right!=NULL){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            maxNode=max(maxNode,dfs(root->right,graph));
        }
        if(root->left!=NULL){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            maxNode=max(maxNode,dfs(root->left,graph));
        }
        return maxNode;
    }
    int bfs(unordered_map<int,vector<int>>&graph,int start,int maxNode){
        vector<bool>visited(maxNode+1, false);
        queue<int>queue;
        visited[start]=true;
        queue.push(start);
        int time=-1;
        while(!queue.empty()){
            int size=queue.size();
            for(int i=0;i<size;i++){
                int curr=queue.front();
                queue.pop();
                for(auto &next:graph[curr]){
                    if(!visited[next]){
                        queue.push(next);
                        visited[next]=true;
                    }
                }
            }
            time++;
        }
        return time;
    }
};
int main()
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(2);
    cout << s.amountOfTime(root, 3) << endl;
    return 0;
}
