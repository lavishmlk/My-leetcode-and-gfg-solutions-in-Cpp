class Solution {
public:
    
  void combinations(int n,int k,vector<vector<int>>&ans,vector<int>temp,int start,int num){
        
        if(k==num){
            ans.push_back(temp);
            return;
        }
        
     for(int i=start;i<n;i++){
         
         temp.push_back(i+1);    
         combinations(n,k,ans,temp,i+1,num+1);
         temp.pop_back();
     }
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        if(n<k)return ans;
       combinations(n,k,ans,temp,0,0);
         return ans;
    }
};