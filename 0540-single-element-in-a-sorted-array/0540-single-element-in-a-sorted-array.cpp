class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        
     int low=0;
        int high=arr.size()-1;
 
        while(low<=high){
            int mid=low+(high-low)/2;
          int lval=mid==0?-1:arr[mid-1];
            int rval=mid==(arr.size()-1)?-1:arr[mid+1];
            if(arr[mid]!=rval && arr[mid]!=lval){
                return arr[mid];
            }
            if(arr[mid]==lval){
                 if((mid-low+1)%2!=0){
                     high=mid-2;
                 }
                else{
                    low=mid+1;
                }
            }
            else{
                if((high-mid+1)%2!=0){
                    low=mid+2;
                }
                else{
                    high=mid-1;
                }
            }
        }
           return -1;
   
    }
};