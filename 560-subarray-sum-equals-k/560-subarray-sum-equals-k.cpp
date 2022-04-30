class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        
        int ans=0;
        unordered_map<int,int>m;
        m[0]=1;
        int sum=0;
        int Count=0;
        for(int i=0;i<nums.size();i++){
            
            sum=sum+nums[i];
            
            if(m.find(sum-k)!=m.end()){
                Count=Count+m[sum-k];
            }
            
            m[sum]++;
            
            
        }
        return Count;
    }
};