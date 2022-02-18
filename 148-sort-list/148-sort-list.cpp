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
        return left->next;
    }
    
    void Randomize(ListNode* head){
         int size=0;
        ListNode* curr=head;
        while(curr!=NULL){
            size++;
            curr=curr->next;   
        }
        int randomno=rand()%size;
        
       curr=head;
        while(randomno--){
         curr=curr->next;   
        }
        swap(curr->val,head->val);
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        
        Randomize(head);
       ListNode* partitionednode=partition(head,head->val);
        ListNode* left=sortList(partitionednode);
        ListNode* right=sortList(head->next);
        
        if(left==NULL){
            head->next=right;
            return head;
        }
            ListNode* lefttail=left;
      while(lefttail->next!=NULL){
          lefttail=lefttail->next;
      }
        if(right==NULL){
             lefttail->next=head;
            return left;
        }
    
        head->next=right;
        lefttail->next=head;
        
        return left;
    }
};