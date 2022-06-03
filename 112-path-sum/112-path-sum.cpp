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
    
    bool helper(TreeNode* root, int targetsum,int sum){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            sum=sum+root->val;
            if(sum==targetsum){
                return true;
            }
            return false;
        }
        
               bool lval= helper(root->left,targetsum,sum+root->val);
        if(lval){
            return true;
        }
       bool rval= helper(root->right,targetsum,sum+root->val);
        if(rval){
            return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetsum) {
        int sum=0;
      return  helper(root,targetsum,sum);
        
        
        

    }
};