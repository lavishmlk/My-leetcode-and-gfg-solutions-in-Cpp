class Solution {
public:
    
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int lval=mid-1>=0?arr[mid-1]:LONG_MIN;
            int rval=mid+1<=arr.size()-1?arr[mid+1]:LONG_MIN;
            
     if(arr[mid]>lval && arr[mid]>rval){
         return mid;
     }
            else if(arr[mid]>lval && arr[mid]<rval){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};