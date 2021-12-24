class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        map<int,int>m;
        
        for(int i=0;i<nums.size();i++){
            
          
            m[nums[i]]++;
              if(m[nums[i]]>n/3 ){
                  bool istrue=false;
        for(int j=0;j<ans.size();j++){
           if(ans[j]==nums[i]){
               istrue=true;
           }
        }
                  if(istrue==false){
                     ans.push_back(nums[i]); 
                  }
                          
               
        
            }
        }
        return ans;
    }
};