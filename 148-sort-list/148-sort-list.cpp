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
    
        ListNode* mergeTwoLists(ListNode* head1, ListNode* head2){
         ListNode* head=new ListNode(-1);
    ListNode* tail=head;
    while(head1!=NULL && head2!=NULL){
     if(head1->val<head2->val){
         tail->next=head1;
         tail=head1;
         head1=head1->next;
     }
     else{
         tail->next=head2;
         tail=head2;
         head2=head2->next;
     }
    }
       if(head1!=NULL){
         tail->next=head1;
         tail=head1;
     }
     else{
         tail->next=head2;
         tail=head2;
     }
     return head->next;
    }
    
       ListNode* middleNode(ListNode* head){
            ListNode* first=head;
            ListNode* second=head;
          
while(second->next!=NULL && second->next->next!=NULL){
first=first->next;
second=second->next->next;
        
        }
    
return first;
    }
    
    ListNode* helper(ListNode* temp){
          if(temp==NULL || temp->next==NULL){
            return temp;
        }
        ListNode* Middle=middleNode(temp);
         
       ListNode* nxt=Middle->next;
        Middle->next=NULL;
        
        ListNode* l1=helper(temp);
       ListNode* l2= helper(nxt);
       return mergeTwoLists(l1,l2);
    }
    
   
    ListNode* sortList(ListNode* head) {
        ListNode* temp=head;
     return helper(temp);
        
    }
    
};