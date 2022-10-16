class Solution {
public:
//saw ayushi youtube
    //tc- n(loop)*logn(upper bound)*log max-min(binary search)
    //https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1685550/Here's-why-Binary-Search-works.-(Explain-it-to-me-like-I'm-5)
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