class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        priority_queue<pair<int,int>>pq;
        
            for(auto it=m.begin();it!=m.end();it++){
            pq.push({it->second,it->first});
        }
        
        
//        for(auto it:m){
//             pq.push({it.second,it.first});
//         }
        
        int x=0;
        vector<int>arr;
        while(x<k){
            arr.push_back(pq.top().second);
            pq.pop();
            x++;
        }
        return arr;
    }
};