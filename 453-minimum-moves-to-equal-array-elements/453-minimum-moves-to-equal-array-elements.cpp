class Solution {
public:
    int minMoves(vector<int>& nums) {
     
        int n=nums.size();
        int sum=0;
        int Min=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
         Min=min(nums[i],Min);}
        
        int numberofmoves = sum - n * Min;
        
        return numberofmoves;
    }
};