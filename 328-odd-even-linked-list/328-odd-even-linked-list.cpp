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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy=new ListNode;
 ListNode* tail=dummy;
 ListNode* dummy2=new ListNode;
 ListNode* tail2=dummy2;
 int Count=1;
 while(head!=NULL){
     if(Count%2!=0){
        tail->next=head;
        tail=head;
        head=head->next;
         Count++;
     }
     else{
         tail2->next=head;
         tail2=head;
         head=head->next;
         Count++;
     }
 }
 tail->next=dummy2->next;;
 tail2->next=NULL;
return dummy->next;
    }
};