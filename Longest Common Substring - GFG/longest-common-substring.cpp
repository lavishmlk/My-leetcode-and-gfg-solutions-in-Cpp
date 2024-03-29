//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //logic av
    //spaceoptimzed code->striver
    int longestCommonSubstr(string s1, string s2, int n, int m)
    {
    vector<int> prev(m+1,0), cur(m+1,0);

    int ans = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + prev[j-1];
                cur[j] = val;
                ans = max(ans,val);
            }
            else
                cur[j] = 0;
        }
        prev=cur;
    }
    return ans;   
    //without space optimization
    // vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    // int ans = 0;
    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(s1[i-1]==s2[j-1]){
    //             int val = 1 + dp[i-1][j-1];
    //             dp[i][j] = val;
    //             ans = max(ans,val);
    //         }
    //         else
    //             dp[i][j] = 0;
    //     }
    // }
    
    // return ans;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends