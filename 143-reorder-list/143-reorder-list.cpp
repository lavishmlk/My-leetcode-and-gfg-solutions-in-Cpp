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
    
      ListNode* reverseList(ListNode* head) {
 
     ListNode* prev=NULL;
        ListNode* curr=head;
            
        while(curr!=NULL){
            ListNode* ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }
        head=prev;
        return head;
        
    }
    
      ListNode* middleNode(ListNode* head) {
      ListNode* first=head;
        ListNode* second=head;
        
        while(second!=NULL && second->next!=NULL){
first=first->next;
second=second->next->next;}
return first;
    }
    
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode* middle=middleNode(head);
     ListNode* reversednode=reverseList(middle);
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=middle){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        
        ListNode*head1=head;
        ListNode* head2=reversednode;
         ListNode* dummy=new ListNode(-1);
           dummy->next=head1;
       ListNode* tail=head1;
        int Count=0;
        while(head1!=NULL && head2!=NULL){   
            if(Count%2==0){
                 head1=head1->next;
            tail->next=head2;
            tail=head2; 
                Count++;
            }
            else{
                  head2=head2->next;
                tail->next=head1;

                tail=head1;
                Count++;
            }
        }    
    }
};