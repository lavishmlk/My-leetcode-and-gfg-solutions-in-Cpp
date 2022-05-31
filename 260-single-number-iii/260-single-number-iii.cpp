class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
          long missingno=nums[0];
     
        for(int i=1;i<nums.size();i++){
            missingno=missingno^nums[i];
        }
        
      long find_set_bit=missingno & ~(missingno-1);
        
        int missno1=0;
        int missno2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&find_set_bit){
                missno1=missno1^nums[i];
            }
            else{
                missno2=missno2^nums[i];
            }
        }
        vector<int>miss;
        miss.push_back(missno1);
         miss.push_back(missno2);
        sort(miss.begin(),miss.end());
        return miss;
    }
};