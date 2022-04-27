class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int window=k;
        deque<int>q;
        vector<int>ans;
        
        // int Max=INT_MIN;
        
        for(int i=0;i<window;i++){
            if(q.size()==0){
                q.push_back(nums[i]);
                continue;
            }
            // Max=max(nums[i],Max);
            if(nums[i]>q.back()){
            while(q.size()>0 && nums[i]>q.back()){
                q.pop_back();
            }
            q.push_back(nums[i]);
            }
            else{
                q.push_back(nums[i]);
            }
        }
        
        ans.push_back(q.front());
        
        // q.push_back(Max);
        
        for(int i=window;i<nums.size();i++){
            
            if(nums[i-k]==q.front()){
                q.pop_front();
            }
            
             if(nums[i]>q.back()){
            while(q.size()>0 && nums[i]>q.back()){
                q.pop_back();
            }
            q.push_back(nums[i]);
            }
            else{
                q.push_back(nums[i]);
            }
            
          ans.push_back(q.front());

            
            
            
//             if(q.size()==0){
//                int Max2=INT_MIN;
//                   int x=i;
//                 int y=window;
//                 while(y-->0){
               
//                      Max2=max(nums[x],Max2);
//                      x--;
//                 }
//                   q.push_back(Max2);
//                 ans.push_back(Max2);
               
//             }
            
//             else{
//             if(nums[i]>q.front()){
//                 q.pop_front();
//                 q.push_back(nums[i]);
//                 ans.push_back(nums[i]);
//             }
//             else{
//                 ans.push_back(q.front());
//             }
//             }
        }
        return ans;
        
    }
};