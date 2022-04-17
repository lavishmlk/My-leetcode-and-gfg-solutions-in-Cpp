class Solution {
public:
    
       vector<vector<int>> twopointer(vector<int>& nums,int left,int target){
        vector<vector<int>>arr;
           int right=nums.size()-1;
           int start=left;
            while(left!=right){
                 if(left>start && nums[left]==nums[left-1]){
                     left++;
                        continue;
                    }
                if(nums[left]+nums[right]==target){
                    vector<int>arr1;
                    arr1.push_back(nums[left]);
                    arr1.push_back(nums[right]);
                    arr.push_back(arr1);
                    left++;
                }
                else if(nums[left]+nums[right]>target){
                    right--;
                }
                else{
                    left++;
                }
            }
       return arr;
    }
    
  vector<vector<int>> ksum(vector<int>& nums, int target,int k,int start){
     if(nums.size()<k){
         vector<vector<int>>empty;
         return empty;
     }
          vector<vector<int>>finalans;
        if(k==2){
           return twopointer(nums,start,target);
        }
                       
                       
        for(int i=start;i<=nums.size()-k;i++){
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
             vector<vector<int>>ans=ksum(nums, target-nums[i],k-1,i+1);
            for(vector<int>pair:ans){
                pair.push_back(nums[i]);
                finalans.push_back(pair);
            }
        }
    return finalans;     
                       
    }
    
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return ksum(nums,target,4,0);
    }
};