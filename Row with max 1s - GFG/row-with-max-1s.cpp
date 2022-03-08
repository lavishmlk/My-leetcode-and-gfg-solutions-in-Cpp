// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
//Normal BS
int transitionPoint(vector<int>&nums, int lo,int hi){
    
        int ans=-1;
        
        while(lo<=hi){
            int mid=(lo+hi)/2;
         
           if(nums[mid]==0){
                lo=mid+1;
            }
            else{
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;}

	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
// 	int left=0;
	int right=m-1;
	int ans=-1;
	int noof1s=0;
	for(int i=0;i<n;i++){
	    int transition=transitionPoint(arr[i],0,right);
	    if(transition!=-1 && m-transition>noof1s){
	        ans=i;
	        noof1s=m-transition;
	       // right=transition-1;
	    }
	}
	return ans;
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends