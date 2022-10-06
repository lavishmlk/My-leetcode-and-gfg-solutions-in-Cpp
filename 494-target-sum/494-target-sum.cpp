class Solution {
public:
    //EDGE CASES:
//     As the array elements are positive integers including zero, we don’t want to find the case when S2 is negative or we can say that totSum is lesser than D, therefore if totSum<target, we simply return 0.
// S2 can’t be a fraction, as all elements are integers, therefore if totSum – target is odd, we can return 0
    //logic aditya v:-count subsets equal to given difference ki tarah hi hai s1-s2=diff and s1+s2=sum

	int countSubsets(vector<int>arr, int target,int idx,int n,vector<vector<int>>&dp){
    
    //agar -ve elements na hote to ye line na likhte coz 
    //target negative ho sakta hai ya target negative hoke doobara +ve ho sakta hai
    if(target<0){
        return 0;
    }
    
    //important -> agar 2 3 5 0 0 hote aur target 10 hota to agar target 0 hote hi return kar dete 1 to khali 1 hi tarika
    //milta par actual me zyada hai isliye last tak jao matlab jabtak index last tak na pahonch jae
    if(idx==n){
         if(target==0)
        return 1;
    else 
    return 0;
    }
    
    if(dp[idx][target]!=-1){
        return dp[idx][target];
    }
int yes=countSubsets(arr,target-arr[idx],idx+1,n,dp);
int no=countSubsets(arr,target,idx+1,n,dp);

return dp[idx][target]=(yes+no);
}
    

int targetSum(int n,int target, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-target<0) return 0;
    if((totSum-target)%2==1) return 0;
    
    //WE CAN ALSO USE TOTSUM+TARGET/2 BUT IT IS GREATER THAN TOTSUM-TAR/2 SO YAHI BETTER HAO COZ ARRAY SIZE BADA HO JAEGA AUR 127 TESTCASE PEFAIL KAREGA
    int s2 = (totSum-target)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return countSubsets(arr,s2,0,arr.size(),dp);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        
     return targetSum(nums.size(),target,nums);
    }
};