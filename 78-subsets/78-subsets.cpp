class Solution {
public:
    //from fraz video
    
   void helper(vector<int>& nums,vector<int>& ans,int idx,vector<vector<int>>& finalans){
       
       if(idx==nums.size()){
           finalans.push_back(ans);
           return;
       }
    
       //yes call
       ans.push_back(nums[idx]);
       helper(nums,ans,idx+1,finalans);
       //no call
       ans.pop_back();
       helper(nums,ans,idx+1,finalans);
       
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>finalans;
        vector<int>ans;
        
        helper(nums,ans,0,finalans);
        return finalans;
        
    }
};