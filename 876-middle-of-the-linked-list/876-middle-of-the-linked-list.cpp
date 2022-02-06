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
    ListNode* middleNode(ListNode* head) {
        int size=Size(head);
        if(size==0){
            return NULL;
        }
        else if(size==1){
            return head;
        }
        else{
      ListNode* first=head;
        ListNode* second=head;
        while(second!=NULL && second->next!=NULL){
first=first->next;
            second=second->next->next;
        }
        return first;
    }
    }
};