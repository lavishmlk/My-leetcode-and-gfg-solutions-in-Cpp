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
                  if(k==0)
                Count=Count+it.second*(it.second-1)/2;
                else
            Count=Count+it.second*m[it.first+k];
            }
            
        }
        return Count;
    }
};