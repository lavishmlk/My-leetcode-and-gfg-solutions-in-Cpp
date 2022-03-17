class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int n=matrix.size();
    int m=matrix[0].size();
    
        int low=0;
        int high=m*n-1;
        
        
while(low<=high){
int mid=low+(high-low)/2;
    int rowidx=mid/m;
    int colidx=mid%m;
    
    int newmid=matrix[rowidx][colidx];
    if(newmid==target){
        return true;
    }
    else if(newmid<target){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
    }
        return false;
    }
};

// bool searchMatrix(vector<vector<int>>& arr, int target){

  
// }