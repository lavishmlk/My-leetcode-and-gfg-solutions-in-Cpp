class Solution {
public:
    int pa(vector<int>& arr, int k){
         int n=arr.size();
          unordered_map<int,int>m;
    int count=0;
    
    for(int i=0;i<n;i++){
       auto it=m.find(k+arr[i]);
       if(it!=m.end()){
       int freq=it->second;
           count=count+freq;
       }
  m[arr[i]]++;
    }
    
    return count;
    }
    int countKDifference(vector<int>& arr, int k) {
       int val1=pa(arr,k);
        int val2=pa(arr,-k);
        return val1+val2;
    }
    
//         int getPairsCount(int arr[], int n, int k) {
//     unordered_map<int,int>m;
//     int count=0;
    
//     for(int i=0;i<n;i++){
//        auto it=m.find(k-arr[i]);
//        if(it!=m.end()){
//        int freq=it->second;
//            count=count+freq;
//        }
//   m[arr[i]]++;
//     }
    
//     return count;
//     }
};