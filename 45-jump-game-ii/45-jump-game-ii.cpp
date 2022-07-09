class Solution {
public:
    
       long helper(vector<int>& nums,int src,vector<long>&dp){
           
           if(src==nums.size()-1){
               return 0;
           }
           if(dp[src]!=-1){
               return dp[src];
           }
           long minanswer=INT_MAX;
           for(int jump=1;jump<=nums[src];jump++){
               if(src+jump<nums.size()){
                  minanswer=min(minanswer,helper(nums,src+jump,dp)+1);
               }
           }
        dp[src]=minanswer;
           return minanswer;
       }
    
    int jump(vector<int>& nums) {
     vector<long>dp(nums.size()+1,-1);
       // for(int i=0;i<dp.size();i++){
       //     cout<<dp[i];
       // }
       return (int)helper(nums,0,dp);
    }
};