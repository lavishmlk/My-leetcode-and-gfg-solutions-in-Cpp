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
    
    
        ListNode* middleNode(ListNode* head){
            ListNode* first=head;
            ListNode* second=head;
          
while(second->next!=NULL && second->next->next!=NULL){
first=first->next;
second=second->next->next;
        
        }
    
return first;
    }
    
    
     void helper(ListNode* &head,ListNode* &temp){ 
     
     if(temp->next==NULL){
         head=temp;
         return;
     }
     helper(head,temp->next);
     temp->next->next=temp;
     
    }
    
        ListNode* reverseList(ListNode* &head) {
        
        int size=Size(head);
        if(size==0){
            return NULL;
        }
        ListNode* temp=head;
    helper(head,temp);
 temp->next=NULL;
        
        return head;
    }
    
    bool isPalindrome(ListNode* head) {
         int size=Size(head);
        if(size==0 || size==1){
            return true;
        }
        ListNode* middle=middleNode(head);
        middle=middle->next;
        ListNode* reverse=reverseList(middle);
        
        ListNode* node1=head;
        ListNode* node2=middle;
        while(node1!=NULL && node2!=NULL){
            if(node1->val==node2->val){
            node1=node1->next;
            node2=node2->next;
            }
            else{
                return false;
            }
           
        }
         return true;
    }
};