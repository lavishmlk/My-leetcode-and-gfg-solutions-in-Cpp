/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//archit last video 
//with extra space of map O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>m;
        
        Node* temp=head;
        Node* dummy=new Node(-1);
        Node* tail=dummy;
        
        while(temp!=NULL){
            Node* curr=new Node(temp->val);
            m[temp]=curr;
            tail->next=curr;
            tail=curr;
            temp=temp->next;
        }
        
        Node* temp2=head;
        Node* x=dummy->next;
        while(temp2!=NULL){

            //agar auto it use karna hai to use this syntax coz temp2->random can be null
//                 if(temp2->random){
//                     auto it=m.find(temp2->random);
//             x->random=it->second;
//             }
// else{
//     x->random=NULL;
// }
            
            x->random=m[temp2->random];
            temp2=temp2->next;
            x=x->next;
            
        }
        return dummy->next;
    }
};