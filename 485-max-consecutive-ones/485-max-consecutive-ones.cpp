class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int ans=0;
        
        for(int i=0;i<nums.size();i++){
       int end=i+1;
           
            if(nums[i]==0){
                continue;
            }
           int Count=0;
    
            while(i<nums.size() && nums[i]!=0){
                Count++;
                i++;
            }
         
           ans=max(Count,ans);
        }
        
        return ans;
    }
};