// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int memo(int n,vector<int>&dp){
	    
	    if(n==1){
	        return 0;
	    }
	
	    if(dp[n]!=-1){
	        return dp[n];
	    }
	    int val1=INT_MAX;
	    int val2=INT_MAX;
	    int val3=INT_MAX;
	    if(n%3==0){
	     val1=memo(n/3,dp);
	    }
	    
	    else if(n%2==0){
	     val2=memo(n/2,dp);
	    }
	        val3=memo(n-1,dp);
	    
	    int val=min(val1,min(val2,val3));
	    return dp[n]=1+val;
	}
	
	int minSteps(int N) 
	{ vector<int>dp(N+1,-1);
	    return memo(N,dp);
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends