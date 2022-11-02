//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //bro coders
//https://www.youtube.com/watch?v=yRagSKdQgsc
    vector <int> maxOfMin(int arr[], int n)
    {
         stack<int> s;
 
    
    int left[n]; 
    int right[n];
 

    for (int i=0; i<n; i++)
    {
        left[i] = -1;
        right[i] = n;
    }
 
    for (int i=0; i<n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
 
        if (!s.empty())
            left[i] = s.top();
 
        s.push(i);
    }
 

    while (!s.empty())
        s.pop();

    for (int i = n-1 ; i>=0 ; i-- )
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
 
        if(!s.empty())
            right[i] = s.top();
 
        s.push(i);
    }
 

   vector<int>ans(n,0);
 

    for (int i=0; i<n; i++)
    {
       //yahan -2 isliye liya coz suppose arr=1 2 4 3 now for 2 we have a range of 3-0-1=2 i.e 2 ki range 1st
       //aur 2nd index tak hai so 2 elements include karliye.now we have to fill len array i.e ans[len] pe arr[i] fill 
       //karna hai so len in this case is 2 so ans[2]=max(ans[2],arr[i]) but arr me bhi to 0 based indexing hai 
       //so ans[2] nahi ans[1] pe store hoga ye
       
        int len = right[i] - left[i] - 2;
 
      
        ans[len] = max(ans[len], arr[i]);
    }

    for (int i=n-2; i>=0; i--)
        ans[i] = max(ans[i], ans[i+1]);
        
        return ans;
    }
};

//m2- //O(n^2)-Using sliding window max leetcode->k ko bas 1 to n chala de sliding winodw max me
// class Solution
// {
//     public:
//     //Function to find maximum of minimums of every window size.
//     vector <int> maxOfMin(int nums[], int n)
//     {
//         vector<int>result;
//         for(int k=1;k<=n;k++){
//             int Max=INT_MIN;
//               vector<int>ans;
//         deque<int>q;
        
//         for(int i=0;i<k;i++){
//               if(q.size()==0){
//                 q.push_back(nums[i]);
//                 continue;
//             }
//             while(q.size()>0 && q.back()>nums[i]){
//                 q.pop_back();
//             }
//             q.push_back(nums[i]);
//         }
//         // ans.push_back(q.front());
//         Max=q.front();
//         for(int i=k;i<n;i++){
//             if(q.front()==nums[i-k]){
//                 q.pop_front();
//             }
//               while(q.size()>0 && q.back()>nums[i]){
//                 q.pop_back();
//             }
//              q.push_back(nums[i]);
            
//             if(nums[i]<q.front()){
//               Max=max(nums[i],Max);
//             }
//             else{
//                 // ans.push_back(q.front());
//                 Max=max(q.front(),Max);
//             }
           
//         }
//         // return ans;
//         result.push_back(Max);
//         }
//         return result;
//     }
// };

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends