// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
int ans=0;

    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        for(int i=0;i<=N-K;i++){
            int sum=0;
            for(int j=i;j<i+K;j++){
                sum=sum+Arr[j];
            }
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