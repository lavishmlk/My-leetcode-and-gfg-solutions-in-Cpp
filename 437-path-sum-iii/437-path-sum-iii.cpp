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
    int Count=0;
          void helper(TreeNode* root, long long targetsum,long long sum){
        if(root==NULL){
            return;
        }
              
            if(sum+root->val==targetsum){
              Count=Count+1;
            }

             helper(root->left,targetsum,sum+root->val);
             helper(root->right,targetsum,sum+root->val);
    
    }
    
    int pathSum(TreeNode* root, int &targetsum) {
        if(root==NULL){
            return 0;
        }
        int sum=0;
        
      helper(root,(long long)targetsum,sum);
        pathSum(root->left,targetsum);
            pathSum(root->right,targetsum);
          return  Count;
    }
};