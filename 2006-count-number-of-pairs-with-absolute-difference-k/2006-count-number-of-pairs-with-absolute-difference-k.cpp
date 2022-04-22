class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int Count=0;
        for(auto it:m){
            if(m.find(it.first+k)!=m.end()){
            Count=Count+it.second*m[it.first+k];
            }
        }
        return Count;
    }
};