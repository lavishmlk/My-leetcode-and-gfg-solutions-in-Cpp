class Solution {
public:
    //tc-m*log(max)
bool isPossible(vector<int>piles,int mid,int h){
     
    long myhrs=0;
    for(int i=0;i<piles.size();i++){
        //it will give floor
     myhrs=myhrs+piles[i]/mid;
        //to get ceil we have to do this if not fully dividible
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

    //i did this but its giving tle
   // int i=0;
//     while(i<piles.size()){
        
//         if(piles[i]-mid<=0){
//             piles[i]=piles[i]-mid;
//             i++;
//         }
//         else{
//         piles[i]=piles[i]-mid;}
//         myhrs++;
//     }