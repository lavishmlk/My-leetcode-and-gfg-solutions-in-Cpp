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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(root1==NULL && root2==NULL){
            return NULL;
        }
        
              TreeNode* n=new TreeNode;
        if(root1 && root2){
            n->val=root1->val+root2->val;
        }
        else if(root1!=NULL && root2==NULL){
             // n->val=root1->val;
            return root1;
        }
        else{
             // n->val=root2->val;
            return root2;
        }
        
    n->left=mergeTrees(root1->left,root2->left); 
    n->right=mergeTrees(root1->right,root2->right);
        
  return n;
    }
};