// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
       public:
   //arr=pages N=BOOKS mid=maxload M=NOOFSTUDENTS
    bool isPossible(int arr[], int mid, int M,int N){
     int i=0;
     int val=mid;
     int minnoofstudents=0;
     while(i<N){
         mid=val;
     while(mid-arr[i]>=0 && i<N){
         mid=mid-arr[i];
         i++;
     }
        minnoofstudents=minnoofstudents+1;
 }
   if(minnoofstudents>M)
         return false;
     else
         return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int N, int M) 
    {
        int sum=0;
       int Max=INT_MIN;
        for(int i=0;i<N;i++){
            sum=sum+arr[i];
            if(arr[i]>Max){
               Max=arr[i];
            }
        }
        int low=Max;
        int high=sum;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(arr,mid,M,N)==true){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends