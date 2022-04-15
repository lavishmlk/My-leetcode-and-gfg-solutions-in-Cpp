class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        vector<int>arr;
        unordered_map<int,int>m;
        
        
        for(int i=0;i<nums.size();i++){
            
            auto it=m.find(target-nums[i]);
            if(it!=m.end()){
                  arr.push_back(i);
                arr.push_back(it->second);
              
               return arr;
            }
               else{
                   m.insert({nums[i],i});
               }
        
    }
       return arr; 
    }
};