class Solution {
public:
    
  bool ishighest(vector<int>& nums,int mid){
      int lval,rval;
      if(mid-1<0){
          lval=INT_MIN;
      }
           else{
            lval=nums[mid-1];
        }
       if(mid+1>nums.size()-1){
            rval=INT_MIN;
        }
           else{
            rval=nums[mid+1];
        }
       if(lval<nums[mid] && nums[mid]>rval){
           return true;
       } 
  return false;
      
    }
    
    bool islowest(vector<int>& nums,int mid){
        int lval,rval;
          if(mid-1<0){
          lval=INT_MAX;
      }
        else{
            lval=nums[mid-1];
        }
        if(mid+1>nums.size()-1){
            rval=INT_MAX;
        }
        else{
            rval=nums[mid+1];
        }
       if(lval>nums[mid] && nums[mid]<rval){
           return true;
       } 
  return false;
    }
    
    int findMin(vector<int>& nums) {
        if(nums[0]<nums[nums.size()-1]){//if array is not rotated
            return nums[0];
        }
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
           
          if(islowest(nums,mid)){//for checking if its lowest
                return nums[mid];
            }
          else  if(ishighest(nums,mid)){//for checking if its highest
                return nums[mid+1];
            }
          
            //now if 1 side is sorted then other side will be difinitely unsorted
           else if(nums[low]<nums[mid]){
                low=mid+1;
            }
        // same with this else if,if 1 side is sorted then other side will be difinitely unsorted
            else if(nums[mid]<nums[high]){
                high=mid-1;
            }
                   
    
    }
          return nums[low];
                   }
                   
};