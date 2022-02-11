/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         if(head==NULL || head->next==NULL){
            return NULL;
        }
        if(head->next==head){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* n=NULL;
        ListNode* curr=head;
        bool flag=false;
        while(fast!=NULL && fast->next!=NULL){
              slow=slow->next;
                fast=fast->next->next;
            if(fast==slow){
               if(head==slow){
                   return head;
               }
                flag=true;
                 break;
            }
            
        }
        if(flag==true){
            while(curr!=fast){
                curr=curr->next;
                fast=fast->next;
            }
            return curr;
        }
        else{
            return NULL;
        }
            
      
    }
};