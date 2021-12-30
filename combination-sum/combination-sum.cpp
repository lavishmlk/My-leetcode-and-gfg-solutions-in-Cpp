class Solution {
public:
    
    
 void targetsum(vector<int>& candidates,vector<int>&temp,vector<vector<int>>&ans,int sum,int i){
        
    
        if(sum==0){
            ans.push_back(temp);
         return;
        }
            
     
     if(i==candidates.size() || sum<0){
         return;
     }
        
        temp.push_back(candidates[i]);
        targetsum(candidates,temp,ans,sum-candidates[i],i);
        temp.pop_back();
         targetsum(candidates,temp,ans,sum,i+1);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        targetsum(candidates,temp,ans,target,0);
        return ans;
    }
};