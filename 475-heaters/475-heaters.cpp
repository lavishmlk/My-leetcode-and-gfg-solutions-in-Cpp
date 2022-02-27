class Solution {
public:
    
   int bs(vector<int>& nums, int target){
            int lo=0;
        int hi=nums.size()-1;
       //lowerbound me nums.size se hi initialize karte hai
       int ans=nums.size();
      while(lo<=hi){
       
            int mid=(lo+hi)/2;
            
            if(target<=nums[mid]){
        ans=mid;
             hi=mid-1;
            }
            else{
                
                lo=mid+1;
            }
        }
        return ans; 
 
        }
        

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int Max=INT_MIN;
      
        for(int i=0;i<houses.size();i++){
            int lbval=bs(heaters,houses[i]);
            if(lbval==0){
                int minval=abs(heaters[lbval]-houses[i]);
          Max=max(Max,minval);
                }
            else if(lbval==heaters.size()){
                  int ubval=lbval-1;
                   int minval=abs(heaters[ubval]-houses[i]);
                Max=max(Max,minval);
            }
            //Archit ki tarah 4 conditions ki zarurat nhi hai 3 me hi ho jaega
            // else if(abs(houses[i]-heaters[lbval])<abs(houses[i]-heaters[lbval-1])){
            //         int ubval=lbval-1;
            // int minval=abs(heaters[lbval]-houses[i]);
            //    Max=max(Max,minval);
            // }
                    else{
              
                    int ubval=lbval-1;
            // int minval=abs(heaters[ubval]-houses[i]);
                         int minval=min(abs(heaters[lbval]-houses[i]),abs(heaters[ubval]-houses[i]));
               Max=max(Max,minval);
            }
            
        }
        return Max;
    }
};