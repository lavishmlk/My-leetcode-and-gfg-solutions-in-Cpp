class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        
        vector<int>arr(nums.size(),1);
        vector<int>arr2(nums.size(),1);
            
             int prod=1;
        int prod2;
            for(int i=0;i<nums.size();i++){
      prod=prod*nums[i];
                arr[i]=prod;
            }
         prod=1;
        for(int i=nums.size()-1;i>=0;i--){
               prod=prod*nums[i];
                arr2[i]=prod;
        }
        
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                 int x=arr2[i+1];
                ans.push_back(x);
            }
            else if(i==nums.size()-1){
                 int x=arr[i-1];
                ans.push_back(x);
            }
            else{
                int x=arr[i-1]*arr2[i+1];
                ans.push_back(x);
            }
        }
        return ans;
    }
};