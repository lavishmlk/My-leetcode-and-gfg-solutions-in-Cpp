class Solution {
public:
    //pepcoding youtube
    int numOfSubarrays(vector<int>& arr) {
        
        long ans=0;
        int odd=0;
        int even=0;
        int sum=0;
        
        for(int i=0;i<arr.size();i++){
            sum=sum+arr[i];
            
            if(sum%2==0){
                ans+=odd;
                even++;
            }
            else{
                odd++;
                ans+=even+1;
            }
        }
        return (int)(ans%1000000007);
    }
};