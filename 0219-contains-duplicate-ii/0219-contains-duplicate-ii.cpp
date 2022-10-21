class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
        m.insert({nums[0],0});
        // m[nums[0]]=0;
        for(int i=1;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                auto it=m.find(nums[i]);
                if(abs(i-it->second)<=k){
                    return true;
                }
            }
            m[nums[i]]=i;
        }
        return false;
    }
};