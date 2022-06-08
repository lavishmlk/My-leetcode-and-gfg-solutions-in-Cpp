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
    int maxval=INT_MIN;
    int anslevel=1;
   void bfs(TreeNode* root,int level){
       if(root==NULL){
           return;
       }
        
       queue<TreeNode*>q;
       
       q.push(root);
       
       while(q.size()>0){
           int sz=q.size();
           int sum=0;
           
           while(sz--){
         TreeNode* x=q.front();
           q.pop();
           
           sum=sum+x->val;
              
               if(x->left)
           q.push(x->left);
               if(x->right)
           q.push(x->right);
           }
          if(sum>maxval){
              
              anslevel=level;
              maxval=sum;
                cout<<level<<endl;
          }
           level++;
         
       }
    }
    
    int maxLevelSum(TreeNode* root) {
        
        bfs(root,1);
        return anslevel;
    }
};