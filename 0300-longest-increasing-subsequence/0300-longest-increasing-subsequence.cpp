
class Solution {
public:
      //striver article take you forward
//     Time Complexity: O(N*N)
// Space Complexity: O(N*N) + O(N)

// Reason: We are using an auxiliary recursion stack space(O(N)) (see the recursive tree, in the worst case we will go till N calls at a time) and a 2D array ( O(N*N+1)).
  
    int helper(vector<int>& nums,int index,int prev_index,vector<vector<int>>&dp){
        if(index==nums.size()){
            return 0;
        }
        
        if(dp[index][prev_index+1]!=-1){
            return dp[index][prev_index+1];
        }
        
        int yes=0;
        
        if(prev_index==-1 || nums[index]>nums[prev_index]){
        yes= 1+helper(nums,index+1,index,dp);
        }
        int no=0+helper(nums,index+1,prev_index,dp);
        
        return dp[index][prev_index+1]=max(yes,no);
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(nums,0,-1,dp);
    }
};

//m2-from comments of av video 32
// Steps:
// 1. The idea is to replicate the input array to another array. (input arr = arr1, replicated arr = arr2)
// 2. Sort arr2 and remove duplicates
// 3. apply LCS to both arrays (arr1 and arr2)
// 4. return dp [ arr1.size() ] [ arr2.size() ], if it asks for the length of the LIS.