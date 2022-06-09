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
    // Another solution using 2d map -it was in archits vides isse pichla submission is from evernote
    map<int,map<int,vector<int>>>m;
    void DFS(TreeNode* root,int col,int row){
        
        if(root==NULL){
            return;
        }
        
        m[col][row].push_back(root->val);
        
        DFS(root->left,col-1,row+1);
        DFS(root->right,col+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root){
          vector<vector<int>>arr;
        if(root==NULL){
          
            return arr; 
        }
        
        DFS(root,0,0);
        
        
        //for col
        for(auto i:m){
            vector<int>oned;
            //for row
              vector<int>a;
            for(auto j:i.second){
                
                for(auto k:j.second){
                    a.push_back(k);
                 
                }
                   sort(a.begin(),a.end());
                while(a.size()>0){
                    int p=a.front();
                 a.erase(a.begin());
                    oned.push_back(p);
                }
            }
           
            arr.push_back(oned);
        }
        return arr;
    }
};