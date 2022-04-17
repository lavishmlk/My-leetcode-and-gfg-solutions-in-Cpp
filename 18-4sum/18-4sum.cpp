class Solution {
public:
    
       vector<vector<int>> twopointer(vector<int>& nums,int left,int right,int target){
        vector<vector<int>>arr;
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
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
             if(nums.size()<4){
             vector<vector<int>>empty;
            return empty;
        }
        sort(nums.begin(),nums.end());
         vector<vector<int>>finalarray;
        
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
            if(i>0){
            if(nums[i]==nums[i-1]){
                continue;
            }}
               if(j>i+1){
                   if(nums[j]==nums[j-1]){
                       continue;
                   }
               }
        vector<vector<int>>ans=twopointer(nums,j+1,nums.size()-1,target-nums[i]-nums[j]);
       
            for(vector<int>pair:ans){
              pair.push_back(nums[i]);
                 pair.push_back(nums[j]);
                  sort(pair.begin(),pair.end());
                finalarray.push_back(pair);
            }
           
         }
        }
        return finalarray;    
         
    }
};