// { Driver Code Starts
// C++ program to search an element in an array
// where difference between all elements is 1
#include<bits/stdc++.h>
using namespace std;

// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k);


// Driver program to test above function
int main()
{
	int t,n,k,x;
	cin>>t;
	while(t--)
    {

        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>x;
        cout<<search(arr, n, x, k)<<endl;

    }
return 0;
}

// } Driver Code Ends


// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
    int low=0;
   int target=x;
   while(low<n){
       int val=arr[low];
              if(val==target){
           return low;
       }
       int minJump=abs(target-val)/k;
       if(minJump==0){
           minJump=1;
       }
       low=low+minJump;
   }
   return -1;
}    	