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
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL){
            return NULL;
        }
        if(headB==NULL){
            return NULL;
        }
           if(headA==headB){
            return headA;
        }
           
        int sizeofl1=Size(headA);
        int sizeofl2=Size(headB);
    
        if(sizeofl2>sizeofl1){
              ListNode* temp=headB;
            int diff=(sizeofl2-sizeofl1);
            while(diff-->0){
                temp=temp->next;
            }
            //isme pehle check karna padega ki temp==head kyunki agar baad me kara to kya pata abhi hi dono last nodes pe hai aur agar next karne ke baad check kara to null ho jaenge
              while(temp!=NULL && headA!=NULL){
                     if(temp==headA){
                      return temp;
                  }
            temp=temp->next;
                  headA=headA->next;
               
        }
        }
        else{
              ListNode* temp=headA;
              int diff=(sizeofl1-sizeofl2);
                while(diff-->0){
                temp=temp->next;
            }
                          while(temp!=NULL){
                                   if(temp==headB){
                                  return temp;
                              }
            temp=temp->next;
                  headB=headB->next;
                         
        }
        }
        
      return NULL;
        
        
    }
};