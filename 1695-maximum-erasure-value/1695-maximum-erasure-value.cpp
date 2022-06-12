class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int maxsum=0;
        unordered_map<int,int>m;
        int sum=0;
        
        int low=0;
        int high=0;
        
        while(low<nums.size() && high<nums.size()){
        
            if(m.find(nums[high])!=m.end()){
                while(m.find(nums[high])!=m.end() && low<nums.size()){
                    sum=sum-nums[low];
                    m[nums[low]]--;
                    if(m[nums[low]]==0){
                        m.erase(nums[low]);
                    }
                    low++;
                }
            }
                     
                            sum=sum+nums[high];
                          maxsum=max(maxsum,sum);
                    
              m[nums[high]]++;
                      high++;
                   
        }
        return maxsum;
    }
};    