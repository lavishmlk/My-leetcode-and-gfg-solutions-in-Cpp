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
    typedef pair<TreeNode*,unsigned long long int>Pair;
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0; 
        }
     
            
            queue<Pair>que;
        que.push({root,0});
        
        int maxwidth=0;
        
        while(que.size()!=0){
       unsigned long long int leftindex=que.front().second;
      unsigned long long int rightindex=que.front().second;
            int size=que.size();
            while(size-->0){
              Pair p=que.front();
                que.pop();
                
                rightindex=p.second;
                if(p.first->left){
                    que.push({p.first->left,2*p.second+1});
                }
             if(p.first->right){
                    que.push({p.first->right,2*p.second+2});
                }
      maxwidth=max(maxwidth,int(rightindex-leftindex+1));
        }
        
    }
        return maxwidth;
    }
};