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
    //isko bfs se kia hua hai pichle submission me par ye dfs wli approsach hai discuss se uthai
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        fun(root, 0);
        return ans;
    }
    
    void fun(TreeNode* root, int level) {
        if(!root)  return;
        //imp see how we pushed in vector...see my notebook pg 17
        if(ans.size() == level) ans.push_back({root -> val});
        else ans[level].push_back(root -> val);
        fun(root -> left, level + 1);
        fun(root -> right, level + 1);
    }
};