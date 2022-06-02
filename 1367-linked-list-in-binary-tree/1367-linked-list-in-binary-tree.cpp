/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
   bool helper(ListNode* head, TreeNode* root){
       if(head==NULL){
           return true;
       }
            if(root==NULL){
           return false;
       }
     
     if(root->val==head->val){
             bool lval=helper(head->next,root->left);
   if(lval){
       return true;
   }
    bool rval= helper(head->next,root->right);
       if(rval){
           return true;
       }
       
     }
return false;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
if(head==NULL){
    return true;
}
        if(root==NULL){
            return false;
        }
    // bool val=helper(head,root);
    //     if(val){
    //         return true;
    //     }
    //    return isSubPath(head,root->left);
    //    return isSubPath(head,root->right);
        return helper(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};