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
    //   private ListNode temp;
    // private boolean isStop;

     void reorder(ListNode* &head,bool &isStop,ListNode* &temp){
        if (head == NULL) return;
        reorder(head->next,isStop,temp);

        if (!isStop) {
            ListNode* next = temp->next;
            temp->next = head;
            head->next = next;
            temp = next;
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