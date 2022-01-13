class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int lo=0;
        int hi=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            int mid=(lo+hi)/2;
            
            if(target==nums[mid]){
                return mid;
            }
            else if(target>nums[mid]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return -1;
    }
};