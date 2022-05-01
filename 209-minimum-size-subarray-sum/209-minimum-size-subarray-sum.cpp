class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        
        int n=arr.size();
        int minLength=INT_MAX;
        int sum=0;
        int left=0;
        for(int i=0;i<n;i++){
        sum=sum+arr[i];
            
        if(sum>=target){
            while(sum>=target){
                sum=sum-arr[left];
               
               minLength=min(minLength,i-left+1);
                 left++;
            }
        }
            
        }
    if(minLength==INT_MAX){
        return 0;
    }
        return minLength;
    }
};