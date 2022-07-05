
class Solution {
public:
    //DONE BY ME, ALSO SEE ARCHIT CODE-LAST 1ST ACCEPTED
    
    void sortColors(vector<int>& nums) {
        
        int low=0;
        int high=0;
        int mid=0;
        int i=0;
        
        while(i<nums.size() && high<nums.size()){
            if(nums[i]==0){
                low++;
                high++;
                mid++;
            }
            else if(nums[i]==1){
                mid++;
                high++;
            }
            else{
                high++;
            }
            i++;
        }
        for(int i=0;i<nums.size();i++){
            if(i<low){
                nums[i]=0;
            }
            else if(i>=low && i<mid){
                nums[i]=1;
            }
            else{
                nums[i]=2;
            }
        }
    }
};