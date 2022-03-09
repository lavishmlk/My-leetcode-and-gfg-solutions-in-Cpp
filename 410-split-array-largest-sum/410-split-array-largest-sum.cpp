class Solution {
public:
      bool isPossible(vector<int> pages, int maxLoad, int totalStud){
          int books=pages.size();
          int currStud=1;
          int currPages=0;
 //     int i=0;
 //     int val=mid;
 //     int minnoofstudents=0;
 //     while(i<N){
 //         mid=val;
 //     while(mid-arr[i]>=0 && i<N){
 //         mid=mid-arr[i];
 //         i++;
 //     }
 //        minnoofstudents=minnoofstudents+1;
 // }
 //   if(minnoofstudents>M)
 //         return false;
 //     else
 //         return true;
          for(int i=0;currStud<=totalStud && i<books;i++){
              if(currPages+pages[i]<=maxLoad){
                  currPages+=pages[i];
              }
              else{
                  currStud++;
                  currPages=pages[i];
              }
          }
          if(currStud>totalStud){
              return false;
          }
          return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(vector<int> arr, int M) 
    {
        int N=arr.size();
        int sum=0;
       int Max=INT_MIN;
        for(int i=0;i<N;i++){
            sum=sum+arr[i];
            if(arr[i]>Max){
               Max=arr[i];
            }
        }
        int low=Max;
        int high=sum;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(arr,mid,M)==true){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    
    int splitArray(vector<int>& nums, int m) {
        // int* arr=new int[nums.size()];
        // for(int i=0;i<nums.size();i++){
        //     arr[i]=nums[i];
        // }
        // copy(nums.begin(),nums.end(),arr);
        return findPages(nums,m);
    }
};