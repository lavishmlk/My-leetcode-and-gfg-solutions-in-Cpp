class Solution {
public:
    
    int longestOnes(vector<int>& nums, int k) {
     
        int left=0;
        int maxlength=0;
        int right=0;
       
        int countofzero=0;
            while(right<nums.size()){
                if(nums[right]==0){
                    countofzero++;
                }               
                  right++;
              
                while(countofzero>k){
                    if(nums[left]==0){
                        countofzero--;
                    }
                    left++;
                }
                 maxlength=max(maxlength,right-left);
            }
        return maxlength;
        
    }
};