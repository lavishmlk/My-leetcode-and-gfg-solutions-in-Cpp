class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int low=0;
        int high=numbers.size()-1;
        while(low<high){
            if(numbers[low]+numbers[high]==target){
                vector<int>ans;
                ans.push_back(low+1);
                ans.push_back(high+1);
                return ans;
            }
            else if(numbers[low]+numbers[high]<target){
                low++;
            }
            else{
                high--;
            }
        }
        vector<int>empty;
        return empty;
    }
};