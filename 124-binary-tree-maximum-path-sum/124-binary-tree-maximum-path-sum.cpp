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
    
    int maxpathsum=INT_MIN;
    
  int helper(TreeNode* root){
        if(root==NULL){
          return 0;
        }

      
      int ldownward=helper(root->left);
     int rdownward= helper(root->right);
      
      if(ldownward<0 && rdownward<0){
           maxpathsum=max(maxpathsum,root->val);
          return root->val;
      }
      else if(ldownward<0 && rdownward>=0){
            maxpathsum=max(maxpathsum,root->val+rdownward);
          return rdownward+root->val;
      }
      else if(rdownward<0 && ldownward>=0){
            maxpathsum=max(maxpathsum,root->val+ldownward);
          return ldownward+root->val;
      }
       maxpathsum=max(maxpathsum,root->val+ldownward+rdownward);
          return root->val+max(ldownward,rdownward);
      
      
    }
    
    int maxPathSum(TreeNode* root) {
        
        helper(root);
        return maxpathsum;
    }
};