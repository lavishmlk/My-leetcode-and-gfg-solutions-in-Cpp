class Solution {
public:
  //in video 2 greedy around 50//similar to meeting rooms 2
   bool carPooling(vector<vector<int>>& intervals, int capacity) {
       
        // sort(trips.begin(),trips.end(),comp);
          // map<int,int>mend;
        map<int,int>m;
        
        for(int i=0;i<intervals.size();i++){
            if(m.find(intervals[i][1])!=m.end()){
              m[intervals[i][1]]=intervals[i][0]+m[intervals[i][1]];
            }
            else{
                 m[intervals[i][1]]=intervals[i][0];
            }
             if(m.find(intervals[i][2])!=m.end()){
                  m[intervals[i][2]]=-intervals[i][0]+m[intervals[i][2]];
           
               
            }
       else{ 
              m[intervals[i][2]]=-intervals[i][0];
       }   
        }
        int sum=0;
        int maxval=INT_MIN;
          for(auto val:m){
             sum=sum+val.second;
             maxval=max(maxval,sum);
         }
    
         if(maxval<=capacity){
             return true;
         }else{
             return false;
         }
    
    }
};