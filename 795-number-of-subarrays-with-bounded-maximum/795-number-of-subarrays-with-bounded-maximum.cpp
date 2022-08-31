class Solution {
public:
    
    
    int countSubarray(vector<int>& nums,int x){
        
               int left=0;
       long long ans=0;
        int idx=-1;
        int right=0;
        
       while(right<nums.size()){
            
            if(nums[right]>x){
                idx=right;
            }
               
             ans+=idx-0+1;
           right++;
        }
        return ans;
    }
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
long long ans=countSubarray(nums,left-1)-countSubarray(nums,right);
        return int(ans);
    }
};