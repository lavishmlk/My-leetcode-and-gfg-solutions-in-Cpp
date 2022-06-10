class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        //mistake-here i forgot to initialize size of array and without size of array it will give error
        vector<int>ans(nums.size());
        int k=nums.size()-1;
        
        while(low<=high){
            int val1=(nums[low]*nums[low]);
            int val2=nums[high]*nums[high];
            if(val1>val2){
                ans[k]=val1;;
                low++;
            }
            else{
                  ans[k]=val2;
                high--;
            }
           k--; 
        }
        return ans;
    }
};