class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
   int coinsize=coins.size();
        
        int dp[amount+1];
      
        for(int i=1;i<=amount;i++){
       dp[i]=amount+1;
        }
          dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coinsize;j++){
                if(coins[j]<=i){
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
          return dp[amount] > amount ? -1 : dp[amount];
    }
};