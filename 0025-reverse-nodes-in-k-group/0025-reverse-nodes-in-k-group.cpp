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

//Codelibrary from yoesh
//recursive call stack space->O(n)
class Solution {
public:
    int Size(ListNode* head){
        ListNode* temp=head;
        int size=0;
        while(temp->next!=NULL){
            temp=temp->next;
            size++;
        }
        return size+1;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k){    
           
        ListNode* curr=head;
        ListNode* prev=NULL;
        int count=0;
        ListNode* nxt;
        
        if(Size(head)<k){
            return head;
        }
       
while(curr!=NULL && k>count){
 nxt=curr->next;
    curr->next=prev;
    prev=curr;
    curr=nxt;
    count++;
}
        if(nxt!=NULL)
        head->next=reverseKGroup(nxt,k);
        return prev;
    }
};