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
    
    pair<int,int> tiltfunction(TreeNode* root){
         if(root==NULL){
          pair<int,int> my;
             my.first=0;
             my.second=0;
             return my;
        }
        
      pair<int,int> lval= tiltfunction(root->left);
      pair<int,int> rval= tiltfunction(root->right);
        pair<int,int> mytilt;
        mytilt.first=lval.first+rval.first+root->val;
        
        if(root->right && root->left)
     mytilt.second=lval.second+rval.second+abs(lval.first-rval.first);
         else if(root->left)
           mytilt.second=lval.second+abs(lval.first);
              else if(root->right)
                  mytilt.second=rval.second+abs(rval.first);
       
        return mytilt;
    }
    
    int findTilt(TreeNode* root) {
       pair<int,int> ans=tiltfunction(root);
        return ans.second;
    }
};