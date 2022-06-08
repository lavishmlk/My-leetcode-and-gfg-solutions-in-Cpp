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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
   if(root==NULL){
        vector<vector<int>>v;
           return v;
       }
        stack<TreeNode*>ms;
        stack<TreeNode*>cs;
        vector<vector<int>>finalans;
        int level=1;
       ms.push(root);
        
        while(ms.size()>0){
             vector<int>ans;
        while(ms.size()>0){
            
            TreeNode* f=ms.top();
            ms.pop();
            ans.push_back(f->val);
            if(level%2!=0){
                if(f->left!=NULL)
                cs.push(f->left);
                
                    if(f->right!=NULL)
                    cs.push(f->right); 
            
            }
            else{
                    if(f->right!=NULL)
                    cs.push(f->right); 
                
                 if(f->left!=NULL)
                cs.push(f->left);
            }
            
        }
           
         level++;
           
            ms=cs;
            while(cs.size()!=0){
            cs.pop();
            }
             finalans.push_back(ans);
         
        }
         return finalans;
    }
       
};