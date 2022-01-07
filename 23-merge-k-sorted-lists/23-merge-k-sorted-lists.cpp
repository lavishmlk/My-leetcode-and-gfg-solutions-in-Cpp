class Solution {
public:
  
     struct compare
    {
        bool operator()(ListNode* &a,ListNode* &b)
        {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;

          for(ListNode* x:lists){
              if(x!=NULL)
              pq.push(x);
          }   
                    ListNode* head=NULL;
            ListNode* tail=NULL;
        
        while(!pq.empty()){
            
            ListNode* val=pq.top();
            pq.pop();
            
            if(head==NULL){
                // head=val;
                tail=val;
                head=tail;
            }
            else{
                tail->next=val;
                tail=val;   
            }
            
if(val->next){
    pq.push(val->next);
}
        }
        return head;
        
}
};