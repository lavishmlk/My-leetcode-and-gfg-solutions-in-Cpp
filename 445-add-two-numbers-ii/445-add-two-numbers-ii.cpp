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
    ListNode* reverseList(ListNode* &head) {
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
    
  ListNode*  helper(ListNode* l1, ListNode* l2){
                if(l1==NULL&&l2==NULL){
            return NULL;
        }
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        int carry=0;
        ListNode* n=new ListNode;
        ListNode* head=n;
        while(l1!=NULL || l2!=NULL || carry>0){
            
            int d1=l1==NULL?0:l1->val;
            int d2=l2==NULL?0:l2->val;
              ListNode* dummy=new ListNode;
 
            dummy->val=d1+d2+carry;
             dummy->val= dummy->val%10;
            carry=(carry+d1+d2)/10;
            head->next=dummy;
            head=dummy;
            if(l1!=NULL)
            l1=l1->next;
            if(l2!=NULL)
            l2=l2->next;
         
            
        }
        return n->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* n1=reverseList(l1);
       ListNode* n2= reverseList(l2);
    ListNode* resultantNode=helper(n1,n2);
      return  reverseList(resultantNode);
    }
};