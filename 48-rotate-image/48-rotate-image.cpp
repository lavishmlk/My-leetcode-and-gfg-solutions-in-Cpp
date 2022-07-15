class Solution {
public:
  //transpose then swap
    void rotate(vector<vector<int>>& matrix) {
        
        
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                 swap(matrix[i][j],matrix[j][i]);
                }
        }
        
        for(int i=0;i<matrix.size();i++){
            int low=0;
            int high=matrix.size()-1;
            while(low<high){
            swap(matrix[i][low],matrix[i][high]);
                low++;
                high--;
               
            }
        }
        
    }
};