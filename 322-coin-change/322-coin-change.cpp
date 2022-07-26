class Solution {
public:
    //lec 9 method 4 using tabulation
    int coinChange(vector<int>& coins, int amount) {
           int *dp=new int[amount+1];
        for(int i=0;i<amount+1;i++){
            dp[i]=INT_MAX;//-1 bhi rakh sakte the
        }
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int coin:coins){
                if(i-coin>=0 && dp[i-coin]!=INT_MAX){
                    dp[i]=min(dp[i-coin]+1,dp[i]);
                }
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};