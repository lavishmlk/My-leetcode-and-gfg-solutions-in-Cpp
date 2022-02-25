class Solution {
public:
    
   int leftbs(vector<int>& nums, int target){
         int lo=0;
        int hi=nums.size()-1;
       int rightindex=-1;
      while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(target==nums[mid]){
               rightindex=mid;
                hi=mid-1;
            }
            else if(target>nums[mid]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return rightindex;
    }
   int rightbs(vector<int>& nums, int target){
            int lo=0;
        int hi=nums.size()-1;
       int leftindex=-1;
      while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(target==nums[mid]){
              leftindex=mid;
                lo=mid+1;
            }
            else if(target>=nums[mid]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return leftindex;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1,-1};
        }
        vector<int>ans;
        int leftindex=leftbs(nums,target);
        int rightindex=rightbs(nums,target);
        ans.push_back(leftindex);
        ans.push_back(rightindex);
        return ans;
        
    }
};