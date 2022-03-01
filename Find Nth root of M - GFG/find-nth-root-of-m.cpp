// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int x)
	{
	    if(n==1){
	        return x;
	    }
	           long long int lo=1;
      long long  int hi=x;
      while(lo<=hi){
          
          long long int mid=lo+(hi-lo)/2;
          
          long long int val=1;
          for(int i=1;i<=n;i++){
              
             val=val*mid;;
             if(val>x){
                 break;
             }
          }
      
            if(x==val){
                return (int)mid;
            }
            else if(x>val){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return -1;
	
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends