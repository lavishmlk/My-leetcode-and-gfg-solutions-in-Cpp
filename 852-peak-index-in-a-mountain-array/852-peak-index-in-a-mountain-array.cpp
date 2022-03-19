class Solution {
public:
    
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid==0){
                if(arr[mid+1]<arr[mid]){
                    return mid;
                }
                low=mid+1;
            }
            else if(mid==arr.size()-1){
                if(arr[mid-1]<arr[mid]){
                    return mid;
                }
                high=mid-1;
            }
           else if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
               return mid;
            }
            
            else if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1]){
              high=mid-1;
            }
            else{
             low=mid+1;
            }
        }
        return -1;
    }
};