// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //kcodenk
 bool find3Numbers(int A[], int n, int X)
    {
        int l, r;
        //Sorting the elements.
        sort(A, A+n);
    
        //Traversing the array elements.
        for (int i = 0; i < n-2; i++)
        {
            //Taking two pointers. One at element after ith index and another
            //at the last index.
            l = i + 1; 
            r = n-1; 
            while (l < r)
            {
                //If sum of elements at indexes i, l and r is equal 
                //to required number, we return true.
                if( A[i] + A[l] + A[r] == X)
                    return true;
                //Else if the sum is less than required number, it means we need
                //to increase the sum so we increase the left pointer l.
                else if (A[i] + A[l] + A[r] < X)
                    l++;
                //Else the sum is more than required number and we need to
                //decrease the sum so we decrease the right pointer r.
                else 
                    r--;
            }
        }
    
        //returning false if no triplet sum equal to required number is present.
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends