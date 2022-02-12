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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* left=new ListNode;
       ListNode* lefttail=left;
        ListNode* right=new ListNode;
       ListNode* righttail=right;
        ListNode* temp=head;
        int pivot=x;
        while(temp!=NULL){
            if(temp->val<pivot){
                lefttail->next=temp;
                lefttail=temp;
                temp=temp->next;
            }
            else{
                righttail->next=temp;
                righttail=temp;
                temp=temp->next;
            }
        }
       lefttail->next=NULL;
        righttail->next=NULL;
        
        lefttail->next=right->next;
        
        return left->next;
    }
};