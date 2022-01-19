class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int>arr;
        int val1=0;
        int val2=numbers.size()-1;
        
        while(val1<val2){
            if((numbers[val1]+numbers[val2])>target){
                val2--;
            }
            else if((numbers[val1]+numbers[val2])<target){
                val1++;
            }
            else{
                arr.push_back(val1+1);
                arr.push_back(val2+1);
                break;
            }
        }
        return arr;
    }
};