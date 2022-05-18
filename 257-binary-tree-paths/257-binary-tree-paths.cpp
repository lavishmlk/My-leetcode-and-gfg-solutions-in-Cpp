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

  void  helper(TreeNode* root,string path,vector<string>&v){
      if(root==NULL){
          return;
      }
      
      if(root->left==NULL && root->right==NULL){
          path=path+to_string(root->val);
          v.push_back(path);
          return;
      }
      
     helper(root->left,path+to_string(root->val)+"->",v);
      helper(root->right,path+to_string(root->val)+"->",v);
   
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string path;
          vector<string>v;
        helper(root,path,v);   
        return v;
    }
};