class Solution {
public:
    
bool isPossible(vector<int>&piles,int mid,int h){
     
    int myhrs=0;
    for(int i=0;i<piles.size();i++){
     myhrs=myhrs+piles[i]/mid;
        if(piles[i]%mid!=0){
            myhrs++;
        }
    }
    if(myhrs<=h){
        return true;
    }
    else{
        return false;
    }
    }
    
    int minEatingSpeed(vector<int>& arr, int h) {
          // int M=h;
        // int N=arr.size();
  
       int Max=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>Max){
               Max=arr[i];
            }
        }
        int low=1;
        int high=Max;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(arr,mid,h)==true){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};