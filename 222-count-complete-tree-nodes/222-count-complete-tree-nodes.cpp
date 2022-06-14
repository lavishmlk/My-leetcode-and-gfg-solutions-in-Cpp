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
    int leftheight(TreeNode* root){
        if(root==NULL){
            return -1;
        }
        int lh=leftheight(root->left);
        return lh+1;
   
    }
       int rightheight(TreeNode* root){
        if(root==NULL){
            return -1;
        }
        int lh=rightheight(root->right);
        return lh+1;
   
    }
    int countNodes(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        int lh=leftheight(root);
        int rh=rightheight(root);
        if(lh==rh){
            return pow(2,lh+1)-1;
        }
        
        int leftnodes=countNodes(root->left);
        int rightnodes=countNodes(root->right);
        
        
        return leftnodes+rightnodes+1;
    }
};