class Solution {
public:
    
    
    vector<vector<string>>ans;
    void  display( vector<vector<bool>>&grid){
        string a="";
    int n=grid.size();
    vector<string>row;
    
    for (int i = 0; i < n; ++i)
    {   
        a="";
        for (int j = 0; j < n; ++j){
            
                if(grid[i][j]==true){
                    a=a+"Q";
                }
            else{
                a=a+".";
            }
            
            }
        row.push_back(a);
        }
        ans.push_back(row);
    }
    
  void  solve( vector<vector<bool>>&grid,int n,vector<bool>&cols,vector<bool>&diag1,vector<bool>&diag2,int row){
          
       if(row==grid.size()){
           display(grid);
           return;
       }
       
              for(int col=0;col<grid[0].size();col++){
                  
          
                 if(cols[col]==false&&diag1[row+col]==false&&diag2[row-col+n]==false){
                     
                     diag1[row+col]=true;
                     diag2[row-col+grid.size()]=true;
                     cols[col]=true;
                     
                     grid[row][col]=true;
                     solve(grid,n,cols,diag1,diag2,row+1);
                     grid[row][col]=false;
                     diag1[row+col]=false;
                     diag2[row-col+grid.size()]=false;
                     cols[col]=false;
                 }
        }
        
      }
    
    vector<vector<string>> solveNQueens(int n) {
    vector<bool>diag1(2*n-1,false);
        vector<bool>diag2(2*n-1,false);
            vector<bool>col(n,false);
        
        vector<vector<bool>>grid(n,vector<bool>(n,false));
        
        solve(grid,n,col,diag1,diag2,0);
        return ans;
    
    }
};