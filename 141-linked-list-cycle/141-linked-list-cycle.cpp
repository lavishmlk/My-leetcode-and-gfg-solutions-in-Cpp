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
    bool hasCycle(ListNode *head){
        //agar ye dono if wle corner cases nhi likhte tab bhi kaam chal jaata
        if(head==NULL || head->next==NULL){
            return false;
        }
        if(head->next==head){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
              slow=slow->next;
                fast=fast->next->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};