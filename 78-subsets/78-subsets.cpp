class Solution {
public:
    //ITERATIVE SOLUTION, RECURSIVE ISKA PEHLE SUBMIT KAR RAKHA HAI, SAW VIDEO OF PRAKASH SHUKLA
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        ans.push_back({});
        cout<<ans.size();
        for(int i=0; i<n; i++)
        {
            int sz = ans.size();
            
            for(int j=0; j<sz; j++)
            {
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};

// another way to write recursive code
// remember here we didnt pass ans with reference in previous recursive code we passed reference
// class Solution {
// public:
    
//   void  helper(vector<int>& nums,int idx,vector<int>ans,vector<vector<int>>&finalans){
        
//         if(idx==nums.size()){
//             finalans.push_back(ans);
//             return;
//         }
//          helper(nums,idx+1,ans,finalans);
//         ans.push_back(nums[idx]);
//         helper(nums,idx+1,ans,finalans);
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
        
//         vector<int>ans;
//         vector<vector<int>>finalans;
//         // finalans.push_back({});
//        helper(nums,0,ans,finalans);
//         return finalans;
//     }
// };