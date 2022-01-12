// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // creating a 2d array to store the result
        int dp[N+1][N+1];
        for(int i = 0;i < N;i++)
            dp[i][i] = 0;
        
        for(int L = 2;L < N;L++){
            for(int i = 1;i < N-L+1;i++){
                int j = i+L-1;
                dp[i][j] = INT_MAX;
                for(int k = i;k < j;k++){
                    dp[i][j] = min(dp[i][j],
                                   dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
                }
            }
        }
        return dp[1][N-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends