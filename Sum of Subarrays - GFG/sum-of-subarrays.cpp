//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
//raj singh youtube
//https://www.youtube.com/watch?v=AhkB4kM4AYY
    long long subarraySum(long long a[], long long n)
    {
      long long p=1e9+7, sum=0;
        for(long long i=0;i<n;i++)
            sum = (sum + ((((i+1)*a[i])%p)*(n-i))%p)%p;
            
            return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     long long t; 
     cin>>t;
     while(t--)
     {
         long long n; cin>>n;
         long long a[n+5];
         for(long long i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.subarraySum(a, n)<<endl;
     }
    return 0;
}

// } Driver Code Ends