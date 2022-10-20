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

//recursive approach thoda bahot khud kia tha thoda discuss se lia
//
class Solution {
public:

     void reorder(ListNode* &head,bool &isStop,ListNode* &temp){
        if (head == NULL) return;
        reorder(head->next,isStop,temp);

        if (!isStop) {
                head->next=temp->next;
        temp->next=head;
        temp=head->next;
        }

        if (temp != NULL && temp->next == head) {
            temp->next = NULL;
            isStop = true;
        }
    }

    void reorderList(ListNode* head) {
          ListNode* temp = head;
       bool isStop = false;
        reorder(head,isStop,temp);
    }
};

//by archit_>find middle then reverse from middle then use merge sort type of approach
// class Solution {
// public:
    
//       ListNode* reverseList(ListNode* head) {
 
//      ListNode* prev=NULL;
//         ListNode* curr=head;
            
//         while(curr!=NULL){
//             ListNode* ahead=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=ahead;
//         }
//         head=prev;
//         return head;
        
//     }
    
//       ListNode* middleNode(ListNode* head) {
//       ListNode* first=head;
//         ListNode* second=head;
        
//         while(second!=NULL && second->next!=NULL){
// first=first->next;
// second=second->next->next;}
// return first;
//     }
    
//     void reorderList(ListNode* head) {
//         if(head==NULL || head->next==NULL){
//             return;
//         }
//         ListNode* middle=middleNode(head);
//      ListNode* reversednode=reverseList(middle);
//         ListNode* curr=head;
//         ListNode* prev=NULL;
//         while(curr!=middle){
//             prev=curr;
//             curr=curr->next;
//         }
//         prev->next=NULL;
        
//         ListNode*head1=head;
//         ListNode* head2=reversednode;
//          ListNode* dummy=new ListNode(-1);
//        ListNode* tail=dummy;
//         // int Count=0;
//         while(head1!=NULL || head2!=NULL){   
//                  // if(Count%2==0 && head1!=NULL){ ye line likhega tab bhi chal jaega waise par no need
//             if(Count%2==0 && head1!=NULL){
              
//             tail->next=head1;
                  
//             tail=head1; 
//                  head1=head1->next;
//                 // Count++;
//             }
//             else if(head2!=NULL){
                  
//                 tail->next=head2;

//                 tail=head2;
//                 head2=head2->next;
//                 // Count++;
//             }
//         }
//         head=dummy->next;
//     }
// };