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
    //travel and change return height aur calculate dia
    int helper(TreeNode* root,int &ans){
        
             
        if(root==NULL){
            return -1;
        }
        
   int leftval=helper(root->left,ans);
        int rightval=helper(root->right,ans);
        if(leftval+rightval+2>ans){
            ans=leftval+rightval+2;
        }
        return max(rightval,leftval)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
  helper(root,ans);
        return ans;
    }
};