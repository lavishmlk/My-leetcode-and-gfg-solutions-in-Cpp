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
        int left=0;
       int right=size-1;
        while(left<=right){
            ListNode* leftNode=getNode(head,left);
            ListNode* rightNode=getNode(head,right);
            swap(leftNode->val,rightNode->val);
            left++;
            right--;
        }
        return head;
    }
};

