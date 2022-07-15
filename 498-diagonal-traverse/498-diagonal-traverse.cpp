class Solution {
public:
    //coding decoded
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        if(mat.size()==0){
            return {};
        }
        if(mat[0].size()==0){
            return {};
        }
        
        int n=mat.size();
        int m=mat[0].size();
     vector<int>ans;
        
        int row=0;
        int col=0;
        
        for(int i=0;i<m*n;i++){
            
            ans.push_back(mat[row][col]);
            if((row+col)%2==0){
                   if(col==m-1){
                    row++;
                }
                
               else if(row==0){
                    col++;
                }
              
                else{
                    row--;
                    col++;
                }
            }
            else{
                if(row==n-1){
                    col++;
                }
                else if(col==0){
                    row++;
                }
                else{
                    col--;
                    row++;
                }
            }
        }
        return ans;
    }
};