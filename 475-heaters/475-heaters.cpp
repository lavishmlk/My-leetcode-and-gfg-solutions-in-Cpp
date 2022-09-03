class Solution {
public:
    //lower bound hota hai ya to value mil jae nhi to just greater
   int lowerbound(vector<int>& nums, int target){
            int lo=0;
        int hi=nums.size()-1;
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
            int lbval=lowerbound(heaters,houses[i]);
            //now find closest
            
            //this condition means lower bound 0 index pe hai to lowerbound-1 i.e floor does not exist 
            if(lbval==0){
                int minval=abs(heaters[lbval]-houses[i]);
          Max=max(Max,minval);
                }
            //is means ceil does not exist
            else if(lbval==heaters.size()){
                  int floor=lbval-1;
                   int minval=abs(heaters[floor]-houses[i]);
                Max=max(Max,minval);
            }
                    else{
                    int floor=lbval-1;
                         int minval=min(abs(heaters[lbval]-houses[i]),abs(heaters[floor]-houses[i]));
               Max=max(Max,minval);
            }
            
        }
        return Max;
    }
};