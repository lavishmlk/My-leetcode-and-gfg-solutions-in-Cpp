class Solution {
public:
    //https://www.youtube.com/watch?v=2FTwcxPJ6os
    //biweekly 90
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int>m;
        int Max=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]%space]++;
            Max=max(Max,m[nums[i]%space]);
        }
        
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]%space]==Max){
                ans=min(ans,nums[i]);
            }
        }
        return ans;
    }
};