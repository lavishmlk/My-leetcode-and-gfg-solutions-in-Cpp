class Solution {
public:
     vector<vector<int>>v;
    void solve(vector<int>& nums,int count,vector<int>arr){
        
          
        
        if(count==nums.size()){
            v.push_back(arr);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            
            if(arr[i]==-11){
            arr[i]=nums[count];
            solve(nums,count+1,arr);
            arr[i]=-11;
            }
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
     // int arr[nums.size()];
     //    for(int i=0;i<nums.size();i++){
     //        arr[i]=-1;
     //    }
        vector<int>arr(nums.size(),-11);
solve(nums,0,arr);
        return v;
    }
};

