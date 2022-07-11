// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
   static bool comp(const Job &a,const Job &b){
        if(a.profit==b.profit){
            return a.dead>b.dead;
        }
        return a.profit>b.profit;
        
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        
        sort(arr,arr+n,comp);
        int noofjobs=0;
        int maxprofit=0;
        int maxdeadline=0;
        for(int i=0;i<n;i++){
            maxdeadline=max(maxdeadline,arr[i].dead);
        }
        vector<bool>slots(maxdeadline,false);
        
           for(int i=0;i<n;i++){
               for(int j=arr[i].dead-1;j>=0;j--){
                   if(slots[j]==false){
                       slots[j]=true;
                       maxprofit+=arr[i].profit;
                       noofjobs++;
                       break;
                   }
               }
           }
           return {noofjobs,maxprofit};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends