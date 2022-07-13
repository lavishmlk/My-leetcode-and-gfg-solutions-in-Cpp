class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> result;
        //base case when threr are no intervals
        if(interval.size()==0)return result;
        //sort takes O(nlogn) time
        sort(interval.begin(),interval.end());
        //insert the the the first interval in the result
        result.push_back(interval[0]);
        int j=0;
        //Traverse the whole vector .Takes O(n) time
        for(int i=1;i<interval.size();i++)
        {
            //if intevals are overlapping
            if(result[j][1]>=interval[i][0]) result[j][1]=max(result[j][1],interval[i][1]);
            //else they are not overlapping
            else
            {
                j++;
                result.push_back(interval[i]);
            }
        }
        // if we had to traverse result which is a 2d array then we do it in this way
        //     m1:for start values
        // for(auto x:result){
        //    for(auto y:x){
        //        cout<<x[0];
        //    }
        // }
        // //m2 :for all avalues
        //   for(auto x:result){
        //    for(auto y:x){
        //        cout<<y;
        //    }
        // }
        return result;
    }
};



// syntax 2:
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
  
//         if(intervals.size()<=1) return intervals;
       
//         vector<vector<int>> result;
        
//         sort(intervals.begin(), intervals.end()); 
       
//         result.push_back(intervals[0]);
       
//         for(int i=1; i<intervals.size(); i++) {
          
//             if(result.back()[1] >= intervals[i][0]) result.back()[1] = max(result.back()[1] , intervals[i][1]);
           
//             else result.push_back(intervals[i]); 
//         }
//         return result;
//     }
// };