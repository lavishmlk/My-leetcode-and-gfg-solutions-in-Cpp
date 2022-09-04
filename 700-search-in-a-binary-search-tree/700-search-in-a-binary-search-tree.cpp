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
    
    
  
    
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root==NULL){
            return NULL;
        }
        
     
      TreeNode* lfind= searchBST(root->left,val);
          TreeNode* rfind=searchBST(root->right,val);
        
     
        if( lfind!=NULL && lfind->val==val){
          return lfind;
        }
        
        else if( rfind!=NULL && rfind->val==val){
return rfind;
        }
                  if(root->val==val){
            return root;
        }
       
        
return NULL;
    }
};