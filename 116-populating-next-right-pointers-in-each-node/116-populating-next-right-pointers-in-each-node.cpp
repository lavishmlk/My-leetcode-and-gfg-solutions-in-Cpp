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
//see 117 coz 116 and 117 are same code
public:
    Node* connect(Node* root){
        
        Node* curr=root;
  
        
        while(curr!=NULL){
            
                  Node* head=NULL;
        Node* tail=NULL;
            
        while(curr!=NULL){
    
            if(curr->left){
                if(head==NULL)
                    head=tail=curr->left;
                else{
                    tail->next=curr->left;
                    tail=tail->next;
                }
            }
            if(curr->right){
                if(head==NULL)
                    head=tail=curr->right;
            
            else{
                tail->next=curr->right;
                tail=tail->next;
            }
            }
            curr=curr->next;
    }
            curr=head;
    }
        return root;
        
    }
};