// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	


    
  bool ishighest(int nums[],int mid,int n){
      int lval,rval;
      if(mid-1<0){
          lval=INT_MIN;
      }
           else{
            lval=nums[mid-1];
        }
       if(mid+1>n-1){
            rval=INT_MIN;
        }
           else{
            rval=nums[mid+1];
        }
       if(lval<nums[mid] && nums[mid]>rval){
           return true;
       } 
  return false;
      
    }
    bool islowest(int nums[],int mid,int n){
        int lval,rval;
          if(mid-1<0){
          lval=INT_MAX;
      }
        else{
            lval=nums[mid-1];
        }
        if(mid+1>n-1){
            rval=INT_MAX;
        }
        else{
            rval=nums[mid+1];
        }
       if(lval>nums[mid] && nums[mid]<rval){
           return true;
       } 
  return false;
    }
    
    int findMin(int nums[],int n) {
        if(nums[0]<nums[n-1]){
            return 0;
        }
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            //sequence will matter for eg 1 element ho to
          if(islowest(nums,mid,n)){
                return mid;
            }
               else  if(ishighest(nums,mid,n)){
                return mid+1;
            }
          
           else if(nums[low]<nums[mid]){
                low=mid+1;
            }
            else if(nums[mid]<nums[high]){
                high=mid-1;
            }
                   
    
    }
          return 1;
                   }

	int findKRotation(int arr[], int n) {
	   // vector<int>v(n);
	   // for(int i=0;i<n;i++){
	   //     v.push_back(arr[i]);
	   // }
	int val=findMin(arr,n);
	return val;
	}



};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends