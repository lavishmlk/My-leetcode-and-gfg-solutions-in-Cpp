class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
           unordered_map<int,int>m;
        vector<int>arr;
        for(int val:nums1){
        
              
            m[val]++;
          
           
        }
           for(int val:nums2){
        if(m.find(val)!=m.end()){
               arr.push_back(val);
            m[val]--;
            if(m[val]==0){
                m.erase(val);
            }
            }
        }
        return arr;
    }
};