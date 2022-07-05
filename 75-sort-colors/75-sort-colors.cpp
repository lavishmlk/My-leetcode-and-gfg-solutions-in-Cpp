//USING MAP

class Solution {
public:

    void sortColors(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int j=0;
        for(auto i:mp){
           while(i.second){
               nums[j++]=i.first;
               i.second--;
           } 
        }
        return;
    }
};
