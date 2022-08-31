class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int>ans;
        deque<int>q;
        
        for(int i=0;i<k;i++){
              if(q.size()==0){
                q.push_back(nums[i]);
                continue;
            }
            while(q.size()>0 && q.back()<nums[i]){
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        ans.push_back(q.front());
        for(int i=k;i<nums.size();i++){
            if(q.front()==nums[i-k]){
                q.pop_front();
            }
               while(q.size()>0 && q.back()<nums[i]){
                q.pop_back();
            }
             q.push_back(nums[i]);
            
            if(nums[i]>q.front()){
                ans.push_back(nums[i]);
            }
            else{
                ans.push_back(q.front());
            }
           
        }
        return ans;
    }
};