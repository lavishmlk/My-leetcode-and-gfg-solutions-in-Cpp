class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
        m.insert({0,-1});
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
           
            if(m.find(sum%k)!=m.end()){
                if(i-m[sum%k]>=2){
                    return true;
                }
            }
            m.insert({sum%k,i});
        }
        return false;
    }
};