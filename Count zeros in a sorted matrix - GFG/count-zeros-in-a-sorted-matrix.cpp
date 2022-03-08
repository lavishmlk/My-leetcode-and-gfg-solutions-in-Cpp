// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
public:
int transitionPoint(vector<int>nums, int lo,int hi){
    
        int ans=0;
        
        while(lo<=hi){
            int mid=(lo+hi)/2;
         
           if(nums[mid]==0){
               ans=mid+1;
                lo=mid+1;
            }
            else{

                hi=mid-1;
            }
        }
        return ans;}
	int countZeros(vector<vector<int>>arr)
	{int count=0;

	int n=arr.size();
		int right=n-1;
		int index=0;
	for(int i=0;i<n;i++){
		 int transition=transitionPoint(arr[i],0,right);
	     if(transition!=0 && transition>index){
	         index=transition;
	         right=transition-1;
	         count=count+transition;
	    }
	    else{
	       count=count+transition;
	    }
	}
	
	   
	    	 return count;
	}
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>A(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                cin>>A[i][j];
            }
        }
        Solution ob;
        cout<<ob.countZeros(A)<<'\n';
    }
    return 0;
}
  // } Driver Code Ends