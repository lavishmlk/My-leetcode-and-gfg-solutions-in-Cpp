class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int prod=1;
        int left=0;
        int Count=0;
        
        for(int i=0;i<nums.size();i++){
            
            prod=prod*nums[i];
            
            while(left<=i && prod>=k){
                prod=prod/nums[left];;
                    left++;
            }
            Count=Count+(i-left+1);
            
        }
        return Count;
    }
};