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
int DFS(TreeNode* root, TreeNode* target, int k, vector<int>& res){
        if(root == NULL) return -1;
        if(root == target){
            Kdistance(root, NULL, k, res);
            return 1;
        }
        
        int left = DFS(root->left, target, k, res);
        if(left >= 0){
            Kdistance(root, root->left, k - left, res);
            return left + 1;
        }
        
        int right = DFS(root->right, target, k, res);
        if(right >= 0){
            Kdistance(root, root->right, k - right, res);
            return right + 1;
        }
        
      return -1;  }
    
//     vector<TreeNode*>nodetorootpath(TreeNode* n,int val){
    
//     vector<TreeNode*>v;
//     if(n==NULL){
//         return v;
//     }
//     if(n->val==val){
//           v.push_back(n);
//           return v;
//     }
    
//    vector<TreeNode*>v1=nodetorootpath(n->left,val);
//    if(v1.size()>0){
     
//               v1.push_back(n);
       
//        return v1;
    
//    }
//    vector<TreeNode*>v2=nodetorootpath(n->right,val);
//    if(v2.size()>0){
       
//            v2.push_back(n);
       
//        return v2;
//    }
   

//    return v;
   
// }


void Kdistance(TreeNode* root, TreeNode* blocker, int k, vector<int>& res){
        if(k < 0 || root == NULL || root == blocker)  return;
        if(k == 0){
            res.push_back(root->val);
            return;
        }
        
        Kdistance(root->left, blocker, k - 1, res);
        Kdistance(root->right, blocker, k - 1, res);
    }


    vector<int> KDistanceNodes(TreeNode* root, TreeNode* target , int k)
    {
        
//        vector<TreeNode*>path=nodetorootpath(root,target);
//         for(int i=0;i<path.size() && i<=k;i++){  
//               vector<int>v=Kdistance(path[i],k-i,i==0?NULL:path[i-1]);
//               if(v.size()>0){
//                    for(int i=0;i<v.size();i++){
//                   ans.push_back(v[i]);
//               }
//               }
             
//  }
          vector<int>ans;
        DFS(root,target,k,ans);
      return ans;
    }
    

    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        
      return KDistanceNodes(root,target,k);
        
    }
};