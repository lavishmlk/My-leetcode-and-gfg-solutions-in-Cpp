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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int size=Size(head);
//         if(size==0||size==1){
//             return NULL;
//         }
 
        ListNode* prev=NULL;
        ListNode* first=head;
        ListNode* second=head;
        
        while(second!=NULL && n>0){
            second=second->next;
            n--;//learn about this
        }
        while(second!=NULL){
            second=second->next;
            prev=first;
            first=first->next;
        }
     if(first==head){
        
         head=head->next;
          prev=head;
         delete first;
     }
        else{
              prev->next=first->next;
        delete first;
     
        }
         return head;
    }
};