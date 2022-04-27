class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int start=0;
        
        int ans=INT_MIN;
        
        for(int i=start;i<nums.size();i++){
       int end=i+1;
             int Count;
            if(nums[i]==0)
            Count=0;
            else
             Count=1;
            while(end<nums.size() && nums[end]!=0){
                Count++;
                end++;
            }
           ans=max(Count,ans);
        }
        
        return ans;
    }
};