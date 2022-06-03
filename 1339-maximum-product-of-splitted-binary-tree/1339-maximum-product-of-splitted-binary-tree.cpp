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
  void findtreesum(TreeNode* root,int &sum){
      if(root==NULL){
          return;
      }
        sum=sum+root->val;
        findtreesum(root->left,sum);
        findtreesum(root->right,sum);
    }
    
   long ans=0;
   int helper(TreeNode* root,int treesum){
       
       if(root==NULL){
           return 0;
       }
        
        int lsum=helper(root->left,treesum);
        int rsum=helper(root->right,treesum);
        
       long val1=lsum+rsum+root->val;
       long val2=treesum-(val1);
       if((val1*val2)>ans){
           ans=val1*val2;
       }
        return root->val+lsum+rsum;
    }
    
    int maxProduct(TreeNode* root) {
        int sum=0;
     findtreesum(root,sum);
        helper(root,sum);
        return (int)(ans%1000000007);
    }
};