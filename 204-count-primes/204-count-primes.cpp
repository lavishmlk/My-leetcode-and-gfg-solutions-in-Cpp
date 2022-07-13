class Solution {
public:
    //tc-> https://leetcode.com/problems/count-primes/discuss/473021/Time-Complexity-O(log(log(n))-Explained
    int countPrimes(int n) {
        
        bool* isPrime=new bool[n];
        
        for(int i=2;i<n;i++){
            isPrime[i]=true;
        }
        
        for(int i=2;i*i<n;i++){
            
            if(isPrime[i]!=true){
                continue;
            }
            for(int j=i*i;j<n;j=j+i){
                isPrime[j]=false;
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
            if(isPrime[i]==true){
                count++;
            }
        }
        return count;
    }
};