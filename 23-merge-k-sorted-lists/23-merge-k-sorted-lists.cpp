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
  //Brute force O(N*K^2)
    int minidx(vector<ListNode*>& lists){
         int Min=INT_MAX;
  int idx=-1;
        for(int i=0;i<lists.size();i++){
             if(lists[i]!=NULL && lists[i]->val<Min){
                Min=lists[i]->val;
                 idx=i;
            }
        }
        return idx;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* head=dummy;
        ListNode* tail=dummy;
      
        while(true){
            
             int Minidx=minidx(lists); 
            if(Minidx==-1){
                break;
            }
            tail->next=lists[Minidx];
            tail=lists[Minidx];
            lists[Minidx]=lists[Minidx]->next;
        }
        return dummy->next;
        
    }
};