class Solution {
public:
    bool isPerfectSquare(int x) {
                 int lo=1;
        int hi=x;
      while(lo<=hi){
          
          long int mid=lo+(hi-lo)/2;
          
        long int val=mid*mid; 
          
            if(x==val){
                return true;
            }
            else if(x>val){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return false;
    }
};