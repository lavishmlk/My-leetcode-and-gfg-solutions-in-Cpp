class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
     int Size1=nums1.size();
     int Size2=nums2.size();
        
        // if(Size2<Size1){
        //     swap(nums1,nums2);
        // }
            if(Size2<Size1){
         return findMedianSortedArrays( nums2,nums1);
        }
        int total=(Size1+Size2+1)/2;
        int N=(Size1+Size2);
        int low=0;
        int high=nums1.size();
  
        while(low<=high){
            int mid=low+(high-low)/2;
            int ar=(mid<nums1.size())?nums1[mid]:INT_MAX;
            int al=(mid-1>=0)?nums1[mid-1]:INT_MIN;
          
              int bl=(total-mid-1)>=0?nums2[total-mid-1]:INT_MIN;
           int br=(total-mid<Size2)?nums2[total-mid]:INT_MAX;
            
           if(al<=br && bl<=ar){
             //even
          if(N%2==0){
          //     int val1=max(al,bl);
          //     int val2=min(ar,br);
          // return (val1+val2)/2.0;
          int arr[4]={al,bl,ar,br};
              sort(arr,arr+4);
              return (arr[1]+arr[2])/2.0;
             }  
            //odd
            else{
        return max(al,bl);
            }
            }
            else if(al>br){
                high=mid-1;
            }
            else{
               low=mid+1; 
            }
            
    
            
        }
        return 0.0;
        
        
    }
};