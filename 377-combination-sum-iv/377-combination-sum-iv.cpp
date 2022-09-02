
    //using tabulation
    //space = o(amount) pehle recursive space was also taken into consideration in memoizaton code
    //cant do more space optimization bcz limited states are not there i-nums[j] kuch bhi ho sakta hai
    // ITS WORKING FOR UNSIGNED INT BUT NOT FOR LONG LONG INT SINCE SIZEOF(LONG LONG INT)==SIZEOF(UNSIGNED INT) TO LONG LONG KE LIYE BHI TO CHALNA CHAHIYE
class Solution {
public:
    
    int permutations(vector<int>&coins,int target){
        
      unsigned int dp[target+1];
        
        dp[0]=1;
          for(int i=1;i<=target;i++){
            dp[i]=0;
        }
    
      
        for(int i=1;i<=target;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0){
                        dp[i]=dp[i]+dp[i-coins[j]];

                }
            }
        }
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>&coins=nums;
        return permutations(coins,target);
    }
};