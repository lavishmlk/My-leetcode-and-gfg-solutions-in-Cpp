/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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

//isme left se mangwate hi return nhi karna coz right wle bhi chahiye ye nodetoroot //path ki tarah nhi hai ki milte hi return kar jao
vector<int> Kdistance(struct TreeNode *root, int k,TreeNode* blocker)
{
    vector<int>v;
     if(root==NULL || k<0 || root==blocker){
    return v;
}

if(k==0){

    v.push_back(root->val);
    return v;
}


   vector<int>v1=Kdistance(root->left,k-1,blocker);
    if(v1.size()>0){
        for(int i=0;i<v1.size();i++){
             v.push_back(v1[i]);
        }
    }
   vector<int>v2=Kdistance(root->right,k-1,blocker);
  if(v2.size()>0){
       for(int i=0;i<v2.size();i++){
             v.push_back(v2[i]);
           
       }
  }
return v;
}

vector<int>ans;
    vector <int> KDistanceNodes(TreeNode* root, int target , int k)
    {
        
       vector<TreeNode*>path=nodetorootpath(root,target);
        for(int i=0;i<path.size() && i<=k;i++){
              vector<int>v=Kdistance(path[i],k-i,i==0?NULL:path[i-1]);
              if(v.size()>0){
                   for(int i=0;i<v.size();i++){
                  ans.push_back(v[i]);
              }
              }
             
        }
            // sort( ans.begin(), ans.end() );
      return ans;
    }
    

    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        int x=target->val;
      return KDistanceNodes(root,x,k);
        
    }
};