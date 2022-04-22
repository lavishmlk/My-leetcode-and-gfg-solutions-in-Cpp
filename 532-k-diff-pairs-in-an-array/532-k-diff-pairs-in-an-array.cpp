class Solution {
public:
    int findPairs(vector<int>& nums, int target) {
           int left = 0, right = 1;
        sort(nums.begin(),nums.end());
        int Count=0;
        
        while (left != nums.size() && right != nums.size()) {
              if(left>0 && nums[left]==nums[left-1]){
                    left++;
                    continue;
                }
            if (left == right) {
                if (target < 0) {
                    left++;
                } else {
                    right++;
                }
                continue;
            }

            int diff = nums[right] - nums[left];

            if (diff == target) {
              
             Count++;
        
                    left++;
            
            } else if (diff < target) {
                right++;
            } else {
                left++;
            }
        }
  return Count;
    }
};