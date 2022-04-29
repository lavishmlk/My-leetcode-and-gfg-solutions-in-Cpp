// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k){
       int left=0;
        unordered_map<char,int>m;
        int maxLength=-1;
        
        for(int right=0;right<s.length();right++){
            
            m[s[right]]++;
            
            while(m.size()>k){
                m[s[left]]--;
                  if(m[s[left]]==0){
                      m.erase(s[left]);
                  }
                left++;
              
            }
            if(m.size()==k)
            maxLength=max(maxLength,right-left+1);
        }
        return maxLength;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends