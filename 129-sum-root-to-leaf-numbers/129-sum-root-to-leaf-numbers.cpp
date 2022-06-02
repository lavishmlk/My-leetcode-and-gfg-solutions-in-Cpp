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
    
   void helper(TreeNode* root,int val,int &ans){
      
       if(root==NULL){
           return;
       }
       val=val*10+root->val;
       if(root->left==NULL && root->right==NULL){
           ans=ans+val;
           return;
       }
       helper(root->left,val,ans);
       helper(root->right,val,ans);
    }
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
     int ans=0;
        int val=0;
    helper(root,val,ans);
        return  ans;
    }
};