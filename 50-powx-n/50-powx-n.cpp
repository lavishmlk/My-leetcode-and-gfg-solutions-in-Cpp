class Solution {
public:
    
    double helper(double x,int n){
               if(n==0){
            return 1.0;
        }
        
        double valOfPower=helper(x,n/2);
        
        if(n%2==0)
        return valOfPower*valOfPower;
        
        return valOfPower*valOfPower*x;
        
    }
    double myPow(double x, int n) {
        
        if(x==0){
            return 0.0;
        }
        
        if(x==1){
            return 1.0;
        }
        if(n<0){
           
            return 1/helper(x,n);
        }
 
        return helper(x,n);
    
    }
};