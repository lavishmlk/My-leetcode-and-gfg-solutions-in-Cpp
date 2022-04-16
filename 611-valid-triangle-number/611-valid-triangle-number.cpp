class Solution {
public:
    //from lintcode 443
     int twoSum2(vector<int> &nums, int lo,int high,int target) {
       sort(nums.begin(),nums.end());
        int count=0;
        // int lo=0;
        // int high=nums.size()-1;

        while(lo<high){

          int sum=nums[lo]+nums[high];
          if(sum<=target){
            
lo++;

          }
          else{  
                count=count+(high-lo);      
high--;
          }

        }
        return count;
    }

    
    int triangleNumber(vector<int>& nums) {
        int Count=0;
        int n=nums.size();
    sort(nums.begin(),nums.end());
               if(n<=2){
            
            return 0;
        }    
       
        for(int i=n-1;i>1;i--){
         
 int ans=twoSum2(nums,0,i-1,nums[i]);
Count=Count+ans;
   
	}
	 return Count;
    }
};