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
     vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*>q;
        vector<vector<int>>v;
   if(root==NULL){
       return v;
   }

        q.push(root);
        
        while(q.size()>0){
             vector<int>smallv;
            int count=q.size();
            for(int i=0;i<count;i++){
                    
                    TreeNode* n=q.front();
                    q.pop();
          
                 smallv.push_back(n->val);
    
          
            if(n->left!=NULL)
                 q.push(n->left);
            
           
                if(n->right!=NULL)
                    q.push(n->right);
                
            
            }
            if(smallv.size()>0){
                   v.push_back(smallv);
            }

        }
       
        return v;
     
      
     
      
        
    }
};