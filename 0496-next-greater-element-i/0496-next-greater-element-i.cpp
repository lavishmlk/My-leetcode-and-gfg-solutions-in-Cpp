class Solution {
public:
    //done by me
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int>m;
        
        int max=nums2[nums2.size()-1];
        stack<int>stk;
        stk.push(nums2[nums2.size()-1]);
        
        m[(nums2[nums2.size()-1])]=-1;
        
        for(int i=nums2.size()-2;i>=0;i--){
            
            while(stk.size()>0 && nums2[i]>stk.top()){
                stk.pop();
            }
            if(stk.size()>0)
            m[nums2[i]]=stk.top();
            else
                m[nums2[i]]=-1;
            
            stk.push(nums2[i]);
        }
        
     vector<int>ans;
    for(int i=0;i<nums1.size();i++){
        ans.push_back(m[nums1[i]]);
    }
        return ans; 
    }
};