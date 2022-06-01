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
    int md=INT_MAX;
    int minDepth(TreeNode* root) {
           if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
               int ldepth= minDepth(root->left);
        int rdepth=minDepth(root->right);
        
        md=min(ldepth,rdepth)+1;
    
        }
        else if(root->left==NULL && root->right!=NULL){
            int rdepth=minDepth(root->right);
            return rdepth+1;
        }
        else   if(root->left!=NULL && root->right==NULL){
           int ldepth= minDepth(root->left);
            return ldepth+1;
        }
        else{
                 int ldepth= minDepth(root->left);
        int rdepth=minDepth(root->right);
        
        md=min(ldepth,rdepth)+1;
        }
     return md;
    }
    
};