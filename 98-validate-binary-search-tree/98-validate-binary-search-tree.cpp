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
    //m1-use max anf min functions seperately
    //m2-use inorder traversal of bst and store in array and if array is sorted return true
    //m3-use pair class or pair in c++ like below
    
    //bool , min, max
    typedef pair<bool,pair<long,long>> Pair;
    
   Pair isBST(TreeNode* root){
        
        if(root==NULL){
            Pair p;
            p.first=true;
            p.second.first=LONG_MAX;
            p.second.second=LONG_MIN;
            return p;
        }
        
           Pair lval= isBST(root->left);
       Pair rval= isBST(root->right);
        
        if(lval.first==false || rval.first==false){
            Pair p;
            p.first=false;
            return p;
        }
        
        if(lval.second.second>=root->val){
            Pair p;
          p.first=false;
            return p;
        }
        if(rval.second.first<=root->val){
            Pair p;
            p.first=false;
            return p;
        }
        
        
            Pair p;
           
            p.second.second=max((long)root->val,max(rval.second.second,rval.second.second));
        p.second.first=min((long)root->val,min(lval.second.first,rval.second.first));
            p.first=true;
            return p;
        
    }
    
    bool isValidBST(TreeNode* root) {
        
     Pair val=isBST(root);
        return val.first;
    }
};