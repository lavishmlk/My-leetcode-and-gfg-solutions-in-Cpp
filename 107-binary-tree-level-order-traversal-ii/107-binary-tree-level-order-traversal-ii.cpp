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
int findMaxLen(TreeNode* root)
{
    if(root==NULL) return 0;
    return 1+max(findMaxLen(root->left),findMaxLen(root->right));
}
void levelOrderRec(TreeNode* root, vector<vector<int>>& vec, int level)
{
    if(root==NULL) return;
      
          //imp see how we pushed in vector see my notebook pg 17
       vec[level].push_back({root -> val});

    levelOrderRec(root->left,vec,level-1);
    levelOrderRec(root->right,vec,level-1);
}

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int>> result;
    if(root==NULL) return result;
    int count = findMaxLen(root);
 
    for(int i = 0; i < count; i++)
    {
        vector<int> temp;
        result.push_back(temp);
    }
    levelOrderRec(root, result, count-1);
    return result;
}

};