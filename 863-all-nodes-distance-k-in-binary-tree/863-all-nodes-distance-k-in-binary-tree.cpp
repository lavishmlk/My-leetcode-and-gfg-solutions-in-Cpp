/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//done by me 2 aur archit ke tarike wle codes bhi hai wo bhi dekhlio
//node to root path mangwao aur k levels down fir print kardo
class Solution {
public:

    vector<TreeNode*>nodetorootpath(TreeNode* n,int val){
    
    vector<TreeNode*>v;
    if(n==NULL){
        return v;
    }
    if(n->val==val){
          v.push_back(n);
          return v;
    }
    
   vector<TreeNode*>v1=nodetorootpath(n->left,val);
   if(v1.size()>0){
     
              v1.push_back(n);
       
       return v1;
    
   }
   vector<TreeNode*>v2=nodetorootpath(n->right,val);
   if(v2.size()>0){
       
           v2.push_back(n);
       
       return v2;
   }
   

   return v;
   
}

void nodeskleveldown(TreeNode* root,int k,TreeNode* blocker,vector<int>&ans){
    if(k<0 || root==NULL || root==blocker){
        return;
    }
    if(k==0 ){
        ans.push_back(root->val);
    }
    
    nodeskleveldown(root->left,k-1,blocker,ans);
    nodeskleveldown(root->right,k-1,blocker,ans);
}
    
    
vector<int>ans;
    vector <int> KDistanceNodes(TreeNode* root, int target , int k)
    {
        
       vector<TreeNode*>path=nodetorootpath(root,target);
        vector<int>ans;
        for(int i=0;i<path.size();i++){
             nodeskleveldown(path[i],k-i,(i==0)?NULL:path[i-1],ans);
        }

      return ans;
    }
    

    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        int x=target->val;
      return KDistanceNodes(root,x,k);
        
    }
};