//https://www.youtube.com/watch?v=vF7DkVJnfVQ
//bro coders youtube
//biweekly 90
//O(n) hi hai shyd
class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        stack<int>stk;
        vector<int>nge(nums.size(),nums.size());
           
            for(int i=nums.size()-1;i>=0;i--){
                while(stk.size()>0 && nums[stk.top()]<=nums[i]){
                    stk.pop();
                }
                
                if(stk.size()>0)
                    nge[i]=stk.top();
                
                stk.push(i);
            }
        
        vector<int>ans(nums.size());
        
        for(int i=0;i<nums.size();i++){
            int l=nge[i]+1;
            // int idx=first_larger+1;
            
            while(l<nums.size() && nums[i]>=nums[l]){
                l=nge[l];
            }
            if(l>=nums.size()){
                ans[i]=-1;
            }
            else
            ans[i]=nums[l];
            
        }
        return ans;
    }
};

