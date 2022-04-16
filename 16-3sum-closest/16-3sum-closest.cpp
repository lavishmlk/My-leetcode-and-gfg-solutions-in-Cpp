class Solution {
public:
    
       int twoSum(vector<int> &nums,int lo, int high, int target) {
     
 int nearest=INT_MAX;
           int ans=0;
  
        while(lo<high){

          int sum=nums[lo]+nums[high];
          if(sum<target){
              if(target-sum<nearest){
           nearest=target-sum;
              ans=sum;}
           
lo++;
          }
          else if(sum>target) {  
              if(sum-target<nearest){
                  nearest=sum-target;
                  ans=sum;
              }
            
high--;
          }
          else{
             return sum;
          }
        }
        return ans;
    }
    
    
    int threeSumClosest(vector<int>& nums, int target) {
           
        int nearest=INT_MAX;
           sort(nums.begin(),nums.end());
        int finalans=0;
               if(nums.size()<=2){
            
            return 0;
        }    
       
        for(int i=0;i<nums.size()-2;i++){
         
 int ans=twoSum(nums,i+1,nums.size()-1,target-nums[i]);
if(abs(ans+nums[i]-target)<nearest){
    nearest=abs(ans+nums[i]-target);
    finalans=ans+nums[i];
}
        }
    return finalans;
    }
};