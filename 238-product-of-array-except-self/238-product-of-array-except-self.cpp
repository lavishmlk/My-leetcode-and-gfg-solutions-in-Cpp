class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>arr2(nums.size(),1);
            
             int prod=1;
        
        for(int i=nums.size()-1;i>=0;i--){
               prod=prod*nums[i];
                arr2[i]=prod;
        }
        
        vector<int>ans;
        prod=1;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                
                 int x=arr2[i+1];
                ans.push_back(x);
            }
            else if(i==nums.size()-1){
               prod=prod*nums[i-1];
                ans.push_back(prod);
            }
            else{
                prod=prod*nums[i-1];
                int x=prod*arr2[i+1];
                ans.push_back(x);
            }
        }
        return ans;
    }
};