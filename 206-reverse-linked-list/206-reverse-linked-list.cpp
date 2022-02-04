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
class Solution {
public:
    int Size(ListNode* head){
        if(head==NULL){
            return 0;
        }
        int size=0;
        ListNode* temp=head;
        while(temp->next!=NULL){
            size++;
            temp=temp->next;
            
        }
        return size+1;
    }
      ListNode* getNode(ListNode* head,int index) {
            ListNode* temp=head;
            for(int i=0;i<index;i++){
                temp=temp->next;
            }
                return temp;  
    }
    
 void helper(ListNode* &head,ListNode* &temp){ 
     
     if(temp->next==NULL){
         head=temp;
         return;
     }
     helper(head,temp->next);
     temp->next->next=temp;
     
     
    }
    
    ListNode* reverseList(ListNode* head) {
        
        int size=Size(head);
        if(size==0){
            return NULL;
        }
        ListNode* temp=head;
    helper(head,temp);
 temp->next=NULL;
        
        return head;
    }
};

