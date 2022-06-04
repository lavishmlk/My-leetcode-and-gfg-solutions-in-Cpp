class Solution {
public:
    //striver ka dekha
    long long minimumRemoval(vector<int>& beans) {
        
        long long ans=LONG_MAX;
         long long n=beans.size();
         long long sum=0;
        for(int i=0;i<n;i++){
            sum=sum+beans[i];
        }
        sort(beans.begin(),beans.end());
        
        for( int i=0;i<n;i++){
            long long change=sum-(n-i)*beans[i];
ans=min(ans,change);
        }
        return ans;
    }
};