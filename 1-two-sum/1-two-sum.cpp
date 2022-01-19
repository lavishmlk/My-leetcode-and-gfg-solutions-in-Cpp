class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        vector<int>arr;
        unordered_map<int,int>m;
        m.insert({nums[0],0});
        
        for(int i=1;i<nums.size();i++){
            
            auto it=m.find(target-nums[i]);
            if(it!=m.end()){
                arr.push_back(it->second);
                arr.push_back(i);
                break;
            }
               else{
                   m.insert({nums[i],i});
               }
        
    }
        return arr;
    }
};