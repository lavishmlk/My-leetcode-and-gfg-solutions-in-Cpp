class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
        unordered_map<int,int>m;
        
      for(int i=0;i<nums.size()-1;i++){
          for(int j=i+1;j<nums.size();j++){
          int val=nums[i]*nums[j];
       
          m[val]++;
          }
      }
        
        int Count=0;

      for(auto it:m){
          int val=it.second;
       Count=Count+val*(val-1)/2;
          
      }
        return 8*Count;
        
    }
};