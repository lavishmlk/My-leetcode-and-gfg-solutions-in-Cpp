class Solution {
public:
    
    int helper(vector<int>&cost,int n,vector<int>&dp){
        
        //ye bhi ar sakte the but here we have to handle seperately for size of array less than 4 coz these dp 1 will not be filled ans will always come -1
        // if(n==cost.size()-1 || n==cost.size()-2){
        //     return cost[n];
        // }
        if(n>=cost.size()){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int val1=helper(cost,n+1,dp);
        int val2=helper(cost,n+2,dp);
        
        return dp[n]=cost[n]+min(val1,val2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
       vector<int>dp(cost.size()+1,-1);
       
       helper(cost,0,dp);
    
       return min(dp[0],dp[1]);
    }
};