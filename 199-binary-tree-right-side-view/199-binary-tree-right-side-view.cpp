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
    
    vector<int>ans;
void helper(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    
    while(q.size()>0){
        int sz=q.size();
       for(int i=0;i<sz;i++){
              if(i==sz-1){
               ans.push_back(q.front()->val);
           }
           TreeNode* qval= q.front();
           q.pop();
           
        
           
           if(qval->left)
           q.push(qval->left);
           if(qval->right){
               q.push(qval->right);
           }
        }
    }
}
    
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        helper(root);
         return ans;
    }
};