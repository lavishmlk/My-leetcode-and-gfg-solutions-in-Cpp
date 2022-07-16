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
    
TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int inL,int inR,int preIdx,unordered_map<int,int>&m){
    if(inL>inR){
        return NULL;
    }
         if(inL==inR){
                TreeNode* root=new TreeNode(preorder[preIdx]);
            return root;
        }
        TreeNode* root=new TreeNode(preorder[preIdx]);
    
          auto it=m.find(preorder[preIdx]);
       int inIdx=it->second;
    
    //this will also give ans but it will change all the indices to 0 so why use it
    // int inIdx=m[preorder[preIdx]];
    
    root->left=helper(preorder,inorder,inL,inIdx-1,preIdx+1,m);
    root->right=helper(preorder,inorder,inIdx+1,inR,preIdx+1+(inIdx-inL),m);
    return root;    
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return helper(preorder,inorder,0,inorder.size()-1,0,m);
    }
};