// https://www.youtube.com/watch?v=zX9k1XvVUXI
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>m;
        vector<vector<string>>ans;
        
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            
            m[temp].push_back(strs[i]);
            
        }
        
        for(auto x:m){
            vector<string>temp=x.second;
            ans.push_back(temp);
        
        }
        return ans;
    }
};