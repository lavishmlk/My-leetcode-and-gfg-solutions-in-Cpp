class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod=1; 
        int left=0;  
        int Count=0;
        if(k<=1){
            return 0;
        }
        for(int i=0;i<nums.size();i++){   
            prod=prod*nums[i];  
            //if you dont want to write k<=1 then use this comdition in this loop -> left<=i 
            while( prod>=k){
                prod=prod/nums[left];;
                    left++;
            }
            Count=Count+(i-left+1);
        }
        return Count;
    }
};