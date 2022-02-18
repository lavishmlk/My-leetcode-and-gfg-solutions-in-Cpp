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
        dummy->next=head;
        ListNode* tail=head;
        if(head!=NULL)
        head=head->next;
        while(head!=NULL){
            if(head->val==tail->val){
                head=head->next;
            }
            else{
                tail->next=head;
                tail=head;
                head=head->next;
            }
        }
        if(tail!=NULL)
        tail->next=NULL;
      
    return dummy->next;
        
    }
};