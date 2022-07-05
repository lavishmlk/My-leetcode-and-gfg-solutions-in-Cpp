class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0){
            return 0;
        }
            if(nums.size()==1){
            return 1;
        }
        sort(nums.begin(),nums.end());
        int count=0;
        int maxcount=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                continue;
            }
            if(nums[i]==nums[i+1]-1){
                count++;
                maxcount=max(count,maxcount);
            }
            else{
               count=0;
            }
        }
        return maxcount+1;
    }
};