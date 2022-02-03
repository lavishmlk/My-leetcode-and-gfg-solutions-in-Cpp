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
    
   ListNode* helper(ListNode* left,ListNode* right,int Count,int size){ 
        if(left==NULL){
            return right;
        }
        
       right=helper(left->next,right,Count+1,size);
        if(Count<size/2){
            swap(left->val,right->val);
        }
       return right=right->next;
    }
    
    ListNode* reverseList(ListNode* head) {
        int size=Size(head);
        ListNode* left=head;
        ListNode* right=head;
        int Count=0;
   helper(left,right,Count,size);
        return head;
    }
};

