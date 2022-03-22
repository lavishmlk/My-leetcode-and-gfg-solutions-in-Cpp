class Solution {
public:
    int findPeakElement(vector<int>& nums) {
          int low=0;
        
        int high=nums.size()-1;
        if(nums.size()==1){
            return 0;
        }
        while(low<=high){
      
        int mid=low+(high-low)/2;
            
            if(mid>0 && mid<nums.size()-1){
                if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                  return mid;
                }
                else if(nums[mid]<=nums[mid+1] && nums[mid]>nums[mid-1]){
                    low=mid+1;
                }
                else if(nums[mid]>nums[mid+1] && nums[mid]<=nums[mid-1]){
                    high=mid-1;
                }
                else{
                    //this is the case where dono se hi chota hai to koi bhi side chale jao ans mil jaega
                    // low=mid+1; 
                    high=mid-1;
                }
            }
            else if(mid==0){
                if(nums[0]>nums[1]){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            else if(mid==nums.size()-1){
                if(nums[nums.size()-1]>nums[nums.size()-2]){
                    return nums.size()-1;
                    
                }
                else{
                    return nums.size()-2;
                }
            }
    }
        return -1;
    }
};