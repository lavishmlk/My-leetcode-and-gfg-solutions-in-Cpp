// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	       int twoSum(int *nums,int lo, int high, int target) {
     

           int Count=0;
  
        while(lo<high){

          int sum=nums[lo]+nums[high];
          if(sum<target){
       
           
lo++;
          }
          else if(sum>target) {  
            
high--;
          }
          else{
         Count=Count+1;
         lo++;
          }
        }
        return Count;
    }
	int countTriplet(int nums[], int n)
	{
	    int Count=0;
        
        sort(nums,nums+n);
               if(n<=2){
            
            return 0;
        }    
       
        for(int i=n-1;i>1;i--){
         
 int ans=twoSum(nums,0,i-1,nums[i]);
Count=Count+ans;
   
	}
	 return Count;
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
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends