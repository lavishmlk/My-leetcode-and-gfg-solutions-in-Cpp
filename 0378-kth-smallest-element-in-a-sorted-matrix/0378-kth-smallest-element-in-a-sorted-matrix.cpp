class Solution {
public:
 // ayushi on youtube
    //upper bound calculated elements less than or equal to k for eg for 8 upper bound will be 9 in our matrix so there are 2 elements less than equal to 8
    int kthSmallest(vector<vector<int>>& matrix, int k) {
          int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        while(low < high){
            
            int mid = low + (high - low)/2;
            int count = 0;
            for(int i = 0; i < n; i++){
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                
            }
            
            if(count < k){
                low = mid + 1;
            }else{
                high = mid;
            }
            
        }
        
        return low;
    }
};