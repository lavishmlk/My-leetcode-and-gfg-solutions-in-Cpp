class Solution {
public:
    //done by me
   bool checkPossibility(vector<int>& nums) {
           
        if(nums.size()==1){
            return true;
        }
        int count=0;
        int flag=0;
        
        for(int i=1;i<nums.size();i++){
                if(nums[i]<nums[i-1]){
                    
                    if(i==nums.size()-1){
                        nums[i]=nums[i-1];
                    }
                   else if( nums[i+1]>=nums[i-1]){
                         nums[i]=nums[i+1];
                    flag=1;
                         break;
                    }
                    else{
                    nums[i-1]=nums[i];
                           flag=1;
                         break;
                    }
              
                   
            }
        }
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                count++;
            }

        }
        
        if(count==0 && flag==1){
            return true;
        }
        if(count<=1 && flag==0){
            return true;
        }
        return false;
    }
};