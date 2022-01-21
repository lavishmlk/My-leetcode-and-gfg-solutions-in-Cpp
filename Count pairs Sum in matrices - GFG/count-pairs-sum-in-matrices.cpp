// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	     int r1 = 0, c1 = 0; 
	    int r2 = n - 1, c2 = n - 1; 
	  
	    // While there are more elements 
	    // in both the matrices 
	    int count = 0; 
	    while ((r1 < n) && (r2 >= 0)) { 
	        int val = mat1[r1][c1] + mat2[r2][c2]; 
	  
	        // If true 
	        if (val == x) { 
	  
	            // Increment 'count' 
	            count++; 
	  
	            // Move mat1[][] column 'c1' to right 
	            // Move mat2[][] column 'c2' to left 
	            c1++; 
	            c2--; 
	        } 
	  
	        // If true, move mat1[][] column 'c1' to right 
	        else if (val < x) 
	            c1++; 
	  
	        // Else move mat2[][] column 'c2' to left 
	        else
	            c2--; 
	  
	        // If 'c1' crosses right boundary 
	        if (c1 == n) { 
	  
	            // Reset 'c1' 
	            c1 = 0; 
	  
	            // Increment row 'r1' 
	            r1++; 
	        } 
	  
	        // If 'c2' crosses left boundary 
	        if (c2 == -1) { 
	  
	            // Reset 'c2' 
	            c2 = n - 1; 
	  
	            // Decrement row 'r2' 
	            r2--; 
	        } 
	    } 
	  
	    // Required count of pairs 
	    return count; 
	   
	}
};

// { Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}  // } Driver Code Ends