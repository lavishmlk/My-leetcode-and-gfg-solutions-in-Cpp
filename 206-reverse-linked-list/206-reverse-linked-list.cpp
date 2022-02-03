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
      ListNode* getNode(ListNode* head,int index) {
            ListNode* temp=head;
            for(int i=0;i<index;i++){
                temp=temp->next;
            }
                return temp;  
    }
    
    ListNode* reverseList(ListNode* head) {
        int size=Size(head);
        if(size==0){
            ListNode* n=NULL;
            return n;
        }
        else if(size==1){
            return head;
        }
        else{
     ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* ahead=curr->next;
        
        while(curr!=NULL){
            curr->next=prev;
            prev=curr;
            curr=ahead;
            if(ahead!=NULL)
            ahead=ahead->next;
        }
        head=prev;
        return head;
        }
    }
};

