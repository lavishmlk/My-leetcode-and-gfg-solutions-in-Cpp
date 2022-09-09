class Solution {
public:
    int mySqrt(int x) {
        
        int low=0;
        int high=x;
       long int ans=0;
        
        while(low<=high){
            
           long int mid=low+(high-low)/2;
            long int val=mid*mid;
            if(val>x){
                high=mid-1;
            }
            else if(val<x){
                ans=mid;
                low=mid+1;
            }
            else{
              ans=mid;
                return ans;
            }
        }
        return ans;
    }
};