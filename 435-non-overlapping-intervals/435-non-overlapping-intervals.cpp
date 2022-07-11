class Solution {
public:
    static bool comp( vector<int> &a, vector<int> &b){
         if(a[1]==b[1]){
           return  a[0]<b[0];
         }
       return  a[1]<b[1];
     }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
            sort(intervals.begin(),intervals.end(),comp);
      
      if(intervals.size()==0){
          return 0;
      }

    int count=0;

int limit=INT_MIN;
      for(int i=0;i<n;i++){
          if(limit<=intervals[i][0]){
              count++;
              limit=intervals[i][1];
          }
          
      }
      return intervals.size()-count;
    }
};