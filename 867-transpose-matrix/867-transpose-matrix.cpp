class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        // vector agar n*m hai to m*n ho jaega after transpose therefore m rows and n colums daal diye usme
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};