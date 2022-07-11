// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    //video 1 greedy
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    class Interval{
        public:
        int start;
        int end;
        Interval(){}
        Interval(int start,int end){
            this->start=start;
            this->end=end;
        }
    };
    static bool comp(const Interval &a,const Interval &b){
         if(a.end==b.end){
           return  a.start<b.start;
         }
       return  a.end<b.end;
     }
    int maxMeetings(int start[], int end[], int n)
    {
   
     
        Interval* intervals=new Interval[n];
       
        for(int i=0;i<n;i++){
            intervals[i]=Interval(start[i],end[i]);
            
        }
          sort(intervals,intervals+n,comp);
      int count=0;
      if(n==0){
          return 0;
      }
int limit=INT_MIN;
      for(int i=0;i<n;i++){
          if(limit<intervals[i].start){
              count++;
              limit=intervals[i].end;
          }
          
      }
      return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends