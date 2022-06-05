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

    unordered_map<int,int>m;
    int Count;
   void helper(TreeNode* root, long long targetsum,long long sum){
        if(root==NULL){
            return ;
        }
        sum=sum+root->val;
        
        if(m.find(sum-targetsum)!=m.end()){
            Count=Count+m[sum-targetsum];
        }
       m[sum]++;
        helper(root->left,targetsum,sum);
        helper(root->right,targetsum,sum);
        m[sum]--;
    }
    
    int pathSum(TreeNode* root, int &targetsum) {
long long sum=0;
        m[0]=1;
        helper(root,(long long)targetsum,sum);
        return Count;
    }
};