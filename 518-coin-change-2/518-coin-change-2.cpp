class Solution {
public:
    //tabulation
    //see without tabulation also prev to prev code
    //we want combination so we used method 2 of coun change to do this like 1st loop for 2 will run and within 2 all amount will be explored then loop of 3 amount will run then 5
    //bas combination sum 4 ke loops ulte kar diye coz in 1st iteration we will generate no of ways using 2rs coins then 2nd iteration me 3rs coins just like method 2 of coin change jisse saare combinations generate ho bas
   int dpsolutions(vector<int>& coins, int target,vector<int>&dp){
       
        dp[0]=1;
        for(int i=0;i<coins.size();i++){
            for(int j=1;j<=target;j++){
                if(j-coins[i]>=0)
            dp[j]=dp[j]+dp[j-coins[i]];
                }
        }
        return dp[target];
    }  
    
    int change(int amount, vector<int>& coins) {  
    vector<int>dp(amount+1);
         return  dpsolutions(coins,amount,dp);
    }
};