class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int Xor=nums[0];
        for(int i=1;i<nums.size();i++){
            Xor=Xor^nums[i];
        }
        return Xor;
    }
};