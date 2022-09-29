class Solution {
public:
    //recursive space
    //see prev code for less space
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
    
    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next);
             if(temp->val != p->val){
                 return false;
             }
        temp = temp->next;
        return isPal;
    }
};