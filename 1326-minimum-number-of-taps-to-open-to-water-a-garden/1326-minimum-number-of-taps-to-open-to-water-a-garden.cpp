class Solution {
public:
    //similar to jump game 2 just converted ranges to jumps
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
    
    int minTaps(int n, vector<int>& ranges) {
             if(n == 1) return 1;
     vector<int> jumps(n+1, 0);
        
        for (int i=0; i<ranges.size(); i++) {
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);
            jumps[l] = max(jumps[l], r-l);
        }
        
        
           vector<long>dp(jumps.size()+1,-1);
     
  long val=helper(jumps,0,dp);
        if(val==INT_MAX){
            return -1;
}
        else{
            return (int)val;
        }
    }
};