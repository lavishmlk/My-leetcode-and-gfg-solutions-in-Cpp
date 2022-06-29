class Solution {
public:
    
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int>m;
        m.insert({nums[0],1});
        for(int i=1;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                return true;
            }
            m[nums[i]]++;
         
        }
        return false;
    }
};