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
       void helper(TreeNode* root, int targetsum,int sum,vector<int>&v,vector<vector<int>>&arr){
        if(root==NULL){
            return;
        }
           
        if(root->left==NULL && root->right==NULL){
            sum=sum+root->val;
          
            if(sum==targetsum){
                  v.push_back(root->val);
               arr.push_back(v);
                 v.pop_back();
            }
           
         return;
        }
        v.push_back(root->val);
             helper(root->left,targetsum,sum+root->val,v,arr);
       
helper(root->right,targetsum,sum+root->val,v,arr);
   v.pop_back();
    
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetsum) {
        vector<int>v;
        vector<vector<int>>arr;
        
        helper(root,targetsum,0,v,arr);
        return arr;
    }
};