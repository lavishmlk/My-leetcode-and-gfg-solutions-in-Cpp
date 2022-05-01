class Solution {
public:
    
    
    int countSubarray(vector<int>& nums,int x){
        
               int left=0;
       long long ans=0;
        int idx=-1;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]>x){
                idx=i;
            }
               
             ans+=idx+1;
        }
        return ans;
    }
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
long long ans=countSubarray(nums,left-1)-countSubarray(nums,right);
        return int(ans);
    }
};