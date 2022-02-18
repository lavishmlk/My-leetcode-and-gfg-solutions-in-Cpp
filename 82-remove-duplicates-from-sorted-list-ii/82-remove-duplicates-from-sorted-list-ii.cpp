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
    ListNode* deleteDuplicates(ListNode* head) {
   
       ListNode* dummy=new ListNode;
       ListNode* tail=dummy;
    
    while(head!=NULL){
        if(head->next==NULL || head->val!=head->next->val){
            tail->next=head;
            tail=head;
            head=head->next;
        }
        else{
            ListNode* curr=head;
            while(curr!=NULL && head->val==curr->val){
                curr=curr->next;
            }
            head=curr;
        }
    }
        tail->next=NULL;
        return dummy->next;
    
    }
};