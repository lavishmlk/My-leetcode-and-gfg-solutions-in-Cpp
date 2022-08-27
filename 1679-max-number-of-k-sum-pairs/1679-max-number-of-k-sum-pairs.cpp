class Solution {
public:
    //method 2 using count
    int maxOperations(vector<int>& nums, int k) {
   int count=0;
        unordered_map<int,int>m;
      
        
        for(int i=0;i<nums.size();i++){
            
        if(m.find(k-nums[i])!=m.end()){
           if(m.at(k-nums[i])>0){
               count++;
               m[k-nums[i]]--;
               if(m[k-nums[i]]==0){
                   m.erase(k-nums[i]);
               }
           }
        }
            else{
                m[nums[i]]++;
            }
    }
        return count;
    }
};