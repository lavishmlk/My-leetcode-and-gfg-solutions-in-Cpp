/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //using sfs by archit and 1st submitted by me using dfs
    void DFS(TreeNode* root, vector<int>&levelSum, int level){
        if(root == NULL) return;
        
        if(levelSum.size() > level) 
            levelSum[level]=levelSum[level]+root->val;
        else levelSum.push_back(root->val);
        
        DFS(root->left, levelSum, level + 1);
        DFS(root->right, levelSum, level + 1);
    }
    
    int maxLevelSum(TreeNode* root) {
         vector<int>levelSum;
     levelSum.push_back(0);
        DFS(root, levelSum, 1);
        
        int maxSumLevel = 1;
        for(int i=1; i<levelSum.size(); i++){
            if(levelSum[i] > levelSum[maxSumLevel]){
                maxSumLevel = i;
            }
        }
        return maxSumLevel;
    }
};