// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
              unordered_map<int,int>m;
              unordered_map<int,int>m2;
        vector<int>arr;
          vector<int>finalarr;
        for(int val=0;val<n1;val++){
        
              
            m[A[val]]=1;
          
           
        }
           for(int val=0;val<n2;val++){
        if(m.find(B[val])!=m.end()){
               arr.push_back(B[val]);
            m.erase(B[val]);
            }
        }
            for(int val=0;val<arr.size();val++){
        
              
            m2[arr[val]]=1;
          
           
        }
        
        
        
             for(int val=0;val<n3;val++){
        if(m2.find(C[val])!=m2.end()){
               finalarr.push_back(C[val]);
            m2.erase(C[val]);
            }
        }
        return finalarr;
    }
        

};


// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends