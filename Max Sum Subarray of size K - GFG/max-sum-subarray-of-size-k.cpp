// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        int sum=0;
        int k=K;
       for(int i=0;i<k;i++){
           sum=sum+Arr[i];
       }
       int ans=sum;
       
       for(int i=k;i<N;i++){
           int inc=Arr[i];
           int exc=Arr[i-k];
           sum=sum+inc-exc;
           if(sum>ans){
              ans=sum;
           }
       }
       return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends