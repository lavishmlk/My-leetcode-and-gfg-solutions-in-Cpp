//yu bhi kar sakte hai ya fir isse pehle ek submission jo kiya tha waise bhi usme count bhi badha dia tha //par zarurat nhi hai kyunki unique value staore karta hai map
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int>m;
        vector<int>arr;
        for(int val:nums1){
        
              
            m[val]=1;
          
           
        }
           for(int val:nums2){
        if(m.find(val)!=m.end()){
               arr.push_back(val);
            m.erase(val);
            }
        }
        return arr;
    }
};