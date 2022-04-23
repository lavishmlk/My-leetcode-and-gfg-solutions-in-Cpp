class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        int* arr=new int[nums.size()];
        
        arr[nums.size()-1]=nums[nums.size()-1];
        
        for(int i=nums.size()-2;i>=0;i--){
            arr[i]=max(nums[i],arr[i+1]);
            
            
        }
        int ans=0;
        int i=0;
        int j=i+1;
        while(i<=nums.size()-1 && j<=nums.size()-1){
        
                if(nums[i]<=arr[j]){
                     ans=max(ans,j-i);
                    
                    j++;
                }
            else
             i++;
        }
        return ans;
        
    }
};