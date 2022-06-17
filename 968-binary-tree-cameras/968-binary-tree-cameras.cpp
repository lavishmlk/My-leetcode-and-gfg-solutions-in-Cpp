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
    int camera=0;
    int helper(TreeNode* root){
        if(root==NULL){
            return 1;
        }
        int lval=helper(root->left);
        int rval=helper(root->right);
        
         if(lval==1 && rval==1){
            return -1;
        }
       else if(lval==-1 || rval==-1){
            camera++;
            return 0;
        }
        else if(lval==0 || rval==0){
            return 1;
        }
       
        return 1;
    }
    
    int minCameraCover(TreeNode* root) {
        
       int val= helper(root);
        if(val==-1){
            camera++;
        }
        return camera;
    }
};