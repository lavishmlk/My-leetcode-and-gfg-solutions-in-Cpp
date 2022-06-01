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
    
    pair<int,bool> bal(TreeNode* root){
        
        if(root==NULL){
                pair<int,bool>mp;
            mp.second=true;
            mp.first=0;
            return mp;
        }
      
       pair<int,bool>lpair=  bal(root->left);
       
        pair<int,bool>rpair= bal(root->right);
        
           pair<int,bool>mp;
              mp.first=max(lpair.first,rpair.first)+1;
        
        if(lpair.second!=true || rpair.second!=true){
          mp.second=false;
            return mp;
        }
        
       
        if(abs(lpair.first-rpair.first)>1){
        
            mp.second=false;
            return mp;
        }
        
        mp.second=true;;
        return mp;
    }
        
    bool isBalanced(TreeNode* root) {
         pair<int,bool> ans=bal(root);
        return ans.second;
    }
};