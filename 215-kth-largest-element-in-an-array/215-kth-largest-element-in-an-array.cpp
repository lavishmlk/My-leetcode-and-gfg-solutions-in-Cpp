class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
  
    
    priority_queue<int,vector<int>,greater<int>>pq;
    
int cs=0;
    for(int i=0;i<nums.size();i++){
     
     if(cs<k){
         pq.push(nums[i]);
         cs++;
     }
     else{
         if(pq.top()<nums[i]){
             pq.pop();
             pq.push(nums[i]);
         }
     }
    }

     return pq.top();
    }
};