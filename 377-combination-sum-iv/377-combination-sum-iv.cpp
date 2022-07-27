class Solution {
public:
    
    //its just coin change permutation and the 1st method of coin change queston in which we passed 2 3 5 all in every call 
    //just return 1 in base case thats diff there we returned 0
    
       int  memo(vector<int>&coins,int amount,int  dp[]){
        
           if(amount<0){
               return 0;
           }
       if(amount==0){
           return 1;
       }
       if(dp[amount]!=-1){
           return dp[amount];
       }
       
        int permutation=0;
       for(int i=coins.size()-1;i>=0;i--){
          permutation+=memo(coins,amount-coins[i],dp);  
       }   
 
       return dp[amount]=permutation;
    }
    
    
    
    int combinationSum4(vector<int>& coins, int amount) {
          int dp[amount+1];
        for(int i=0;i<amount+1;i++){
            dp[i]=-1;
        }
return memo(coins,amount,dp);
   
    }
};