// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
 
    string countSort(string arr){
      int len = arr.length();
        int temp[26]={0};
        
        for(int i=0;i<len;i++)
        {
            temp[(arr[i])-97]++;
        }
        
        int i=0,j=0;
      while(j<26){
          if(temp[j]>0){
              arr[i++]=j+97;
              temp[j]--;
          }
          else{
              j++;
          }
      }
        return arr;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}
  // } Driver Code Ends