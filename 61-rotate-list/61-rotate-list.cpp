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
    //done by me
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
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==NULL){
            return head;
        }
        
        ListNode* tempp=head;
        int size=Size(tempp);
        k=k%size;
        
        int rotate=size-k-1;
        
        ListNode* front=head;
        
        while(front->next!=NULL){
            front=front->next;
        }
        front->next=head;
        
        ListNode* prev=head;
        while(rotate--){
            prev=prev->next;
        }
        ListNode* returnpointer=prev->next;
        prev->next=NULL;
        return returnpointer;
        
    }
};