/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    //its given in constrainsts that we cant take extra space therefore its brute force
    
   void helper(Node* root){
        
        queue<Node*>q;
        q.push(root);
        
        while(q.size()>0){
            int sz=q.size();
     
            for(int i=0;i<sz;i++){
                
                Node* val=q.front();
                 q.pop();
                if(i==sz-1){
              val->next=NULL;
                           }
                else{
                    val->next=q.front();
                }
                  if(val->left)
                q.push(val->left);  
                
                     if(val->right)
                q.push(val->right);
              
            }
        }
    }
    
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        helper(root);
        return root;
    }
};