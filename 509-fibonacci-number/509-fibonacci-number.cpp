class Solution {
public:
    
    int fibonacci(int n,int *dp){
          if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int prev1=fib(n-1);
        int prev2=fib(n-2);
       dp[n]=prev1+prev2;
       return prev1+prev2;
    }
    
    int fib(int n) {
        
      int dp[n+1];
        for(int i=0;i<n+1;i++){
            dp[i]=-1;
        }
        
        return fibonacci(n,dp);
    }
};