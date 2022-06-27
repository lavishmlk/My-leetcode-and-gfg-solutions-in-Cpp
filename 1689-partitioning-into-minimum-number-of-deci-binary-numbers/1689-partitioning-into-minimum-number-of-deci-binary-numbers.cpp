class Solution {
public:
    int minPartitions(string n) {
        
        int ans=0;
        for(char x:n){
            int maxval=x-48;
            ans=max(ans,maxval);
        }
        return ans;
    }
};