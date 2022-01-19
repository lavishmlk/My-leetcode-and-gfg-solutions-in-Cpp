class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
 
        int count=0;
        sort(nums.begin(),nums.end());
        int val1=0;
        int val2=nums.size()-1;
        
        while(val1<val2){
            if((nums[val1]+nums[val2])>k){
                val2--;
            }
            else if((nums[val1]+nums[val2])<k){
                val1++;
            }
            else{
              count++;
                val2--;
                val1++;
            }
        }
        return count;
    }
};
