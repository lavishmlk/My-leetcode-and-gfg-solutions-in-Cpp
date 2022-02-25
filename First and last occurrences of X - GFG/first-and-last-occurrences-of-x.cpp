// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
     int leftbs(vector<int>& nums, int target){
         int lo=0;
        int hi=nums.size()-1;
       int rightindex=-1;
      while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(target==nums[mid]){
               rightindex=mid;
                hi=mid-1;
            }
            else if(target>nums[mid]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return rightindex;
    }
   int rightbs(vector<int>& nums, int target){
            int lo=0;
        int hi=nums.size()-1;
       int leftindex=-1;
      while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(target==nums[mid]){
              leftindex=mid;
                lo=mid+1;
            }
            else if(target>=nums[mid]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return leftindex;
    }
    
  
    vector<int> firstAndLast(vector<int> &nums, int n, int target) {
          if(nums.size()==0){
            return {-1};
        }
        vector<int>ans;
        int leftindex=leftbs(nums,target);
        int rightindex=rightbs(nums,target);
        if(leftindex==-1 && rightindex==-1)
        return {-1};
        ans.push_back(leftindex);
        ans.push_back(rightindex);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
  // } Driver Code Ends