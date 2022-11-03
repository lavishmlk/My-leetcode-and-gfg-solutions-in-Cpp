class Solution {
public:
    //brute force pep
    void wiggleSort(vector<int>& nums) {
        
        //SORT THE ARRAY
        sort(nums.begin(),nums.end());
        
        //FILL EXTRA ARRAY
           vector<int>res(nums.size());
    int j = nums.size() - 1;
    int index = 1;
    while (index < nums.size()) {
      res[index] = nums[j--];
      index += 2;
    }
    index = 0;
    while (index < nums.size()) {
      res[index] = nums[j--];
      index += 2;
    }
        // //COPY THE ARRAY
    for (int i = 0; i < res.size(); i++) {
      nums[i] = res[i];
    }
        
    }
};