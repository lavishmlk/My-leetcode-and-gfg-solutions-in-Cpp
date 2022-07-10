class Solution {
public:
    //using tabulation, first see prev code using memo
    int helper(vector<int>&cost,vector<int>&dp){
        
        int n=cost.size();
        for(int i=n-1;i>=0;i--){
       
          int  val1=(i+1<=cost.size()-1)?dp[i+1]:0;
        int val2=(i+2<=cost.size()-1)?dp[i+2]:0;
          dp[i]= min(val1,val2)+cost[i];
         
        }
        
        return min(dp[0],dp[1]);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
       vector<int>dp(cost.size()+1,-1);
     return helper(cost,dp);
    
    }
};