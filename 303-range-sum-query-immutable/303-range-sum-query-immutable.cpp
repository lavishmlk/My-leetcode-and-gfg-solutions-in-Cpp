class NumArray {
public:
    vector<int>arr;
    NumArray(vector<int>& nums) {
      
            for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
                
        }
        //  for(int i=0;i<nums.size();i++){
        // arr.push_back(nums[i]);
        //  }
        arr=nums;
    }
    
    int sumRange(int left, int right) {
        int sum=0;
if(left>0)
        sum=sum+arr[right]-arr[left-1];
        else
        sum=sum+arr[right];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */