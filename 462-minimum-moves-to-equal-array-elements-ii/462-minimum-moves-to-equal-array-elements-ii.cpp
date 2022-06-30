class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int sz=nums.size();
        int median=-1;
        if(nums.size()%2==0){
            median=(nums[sz/2-1]+nums[(sz/2)])/2;
        }
        else{
            median=nums[sz/2];
        }
        
        int minoperations=0;
        for(int i=0;i<sz;i++){
minoperations=minoperations+(abs(nums[i]-median));
        }
        return minoperations;
    }
};