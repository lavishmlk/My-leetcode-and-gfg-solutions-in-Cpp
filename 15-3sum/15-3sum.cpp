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
    vector<vector<int>> threeSum(vector<int>& nums){
        if(nums.size()<=2){
             vector<vector<int>>empty;
            return empty;
        }
        sort(nums.begin(),nums.end());
         vector<vector<int>>finalarray;
        
        for(int i=0;i<nums.size()-1;i++){
            if(i>0){
            if(nums[i]==nums[i-1]){
                continue;
            }}
        vector<vector<int>>ans=twopointer(nums,i+1,nums.size()-1,-nums[i]);
       
            for(vector<int>pair:ans){
              pair.push_back(nums[i]);
                  sort(pair.begin(),pair.end());
                finalarray.push_back(pair);
            }
           
         }
        return finalarray;    
        } 
};
