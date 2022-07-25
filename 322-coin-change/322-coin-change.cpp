class Solution {
public:
    //archit lec 9
    //make all calls and reduce amount and base cASE IS WHEN AMOUNT BECOMES 0
    
   int  memo(vector<int>&coins,int amount,int  dp[]){
        
       if(amount==0){
           return 0;
       }
       if(dp[amount]!=-1){
           return dp[amount];
       }
       
        int Min=INT_MAX;
       for(int i=coins.size()-1;i>=0;i--){
           if(amount-coins[i]<0){
               continue;
           }
              int val=memo(coins,amount-coins[i],dp);  
         Min=min(val,Min);
       }   
  
       //this is necessary to prevent int overflow
       if(Min<INT_MAX)
           Min=Min+1;
       return dp[amount]=Min;
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
         int dp[amount+1];
        for(int i=0;i<amount+1;i++){
            dp[i]=-1;
        }
    int val=memo(coins,amount,dp);
        if(val!=INT_MAX){
            return val;
        }
        return -1;
    }
};