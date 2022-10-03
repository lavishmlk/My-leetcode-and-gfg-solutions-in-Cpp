/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//by striver time-n and no extra space
//use dfs and if from both sides value is not null then that point is lca
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //result
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else { //both left and right are not null, we found our result
            return root;
        }
    }
};

//using Root to node path an easy solution
// class Solution {
// public:
    
//   bool nodeToRootPath(TreeNode* root,TreeNode* target,vector<TreeNode*>&finalvector){
//         if(root==NULL){
//             return false;
//         }
       
//        if(root==target){
//            finalvector.push_back(root);
//            return true;
//        }
        
//         finalvector.push_back(root);
//         bool lval=nodeToRootPath(root->left,target,finalvector);
//       if(lval==true){
//           return true;
//       }
//         bool rval=nodeToRootPath(root->right,target,finalvector);
//       if(rval==true)
//           return true;
//         finalvector.pop_back();
//       return false;
//     }
    
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
//             if(root==NULL){
//             return NULL;
//         }
        
//          vector<TreeNode*>finalvector;
//          vector<TreeNode*>finalvector2;
//         nodeToRootPath(root,p,finalvector);
//         nodeToRootPath(root,q,finalvector2);
        

//           int i = 0;
//         while(i<finalvector.size() and i<finalvector2.size())
//         {
//             if(finalvector[i]->val!=finalvector2[i]->val)
//                 break;
//             i++;
//         }
//         return finalvector[i-1];
//     }
// };