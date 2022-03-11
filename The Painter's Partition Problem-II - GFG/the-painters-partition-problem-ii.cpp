// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
 public:
    // return the maximum element from the array
    int getMax(int arr[], int n)
    {
    	int max = INT_MIN;
    	for (int i = 0; i < n; i++)
    		if (arr[i] > max)
    			max = arr[i];
    	return max;
    }
    
    // return the sum of the elements in the array
    long long getSum(int arr[], int n)
    {
    	long long total = 0;
    	for (int i = 0; i < n; i++)
    		total += arr[i];
    	return total;
    }
    
    // find minimum required painters for given maxlen
    // which is the maximum length a painter can paint
    int numberOfPainters(int arr[], int n, long long maxLen)
    {
    	long long total = 0, numPainters = 1;
    
    	for (int i = 0; i < n; i++) {
    		total += arr[i];
    
    		if (total > maxLen) {
    
    			// for next count
    			total = arr[i];
    			numPainters++;
    		}
    	}
    
    	return numPainters;
    }
    
    long long minTime(int arr[], int n, int k)
    {
    	long long lo = getMax(arr, n);
    	long long hi = getSum(arr, n);
    
    	while (lo < hi) {
    		long long mid = lo + (hi - lo) / 2;
    		long long requiredPainters = numberOfPainters(arr, n, mid);
    
    		// find better optimum in lower half
    		// here mid is included because we
    		// may not get anything better
    		if (requiredPainters <= k)
    			hi = mid;
    
    		// find better optimum in upper half
    		// here mid is excluded because it gives
    		// required Painters > k, which is invalid
    		else
    			lo = mid + 1;
    	}
    
    	// required
    	return lo;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends