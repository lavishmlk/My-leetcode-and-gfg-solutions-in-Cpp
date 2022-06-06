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
    //waise cloned tree pe normal find bhi laga sakte hai coz its given ki unique hai values see //previous submitted code
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(original==NULL || cloned==NULL){
            return NULL;
        }
        
        if(original==target){
            return cloned;
        }
        
     TreeNode* lclone= getTargetCopy(original->left,cloned->left,target);
        if(lclone!=NULL){
            return lclone;
        }
     TreeNode* rclone= getTargetCopy(original->right,cloned->right,target);
        if(rclone!=NULL){
return rclone;}
        
        return NULL;
    }
};