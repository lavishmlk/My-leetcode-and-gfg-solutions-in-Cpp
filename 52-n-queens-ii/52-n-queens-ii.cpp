class Solution {
public:
    
    int Count=0;
      
    bool issafe(vector<string>&board,int x,int y){
       // for check in column
       int n=board.size();
       for(int row=0;row<x;row++){
            if(board[row][y]=='Q'){
                return false;
            }
       }

       // for checking in left diagonal
       int row=x-1,col=y-1;
       while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--; col--;
       }

       // for checking in right diagonal
        row=x-1;
        col=y+1;
       while(row>=0 && col<n){
            if(board[row][col]=='Q'){
                return false;
            }
            row--; col++;
       }
        //if all condition satisfied returning true;
       return true;
    }


    void backtrack(int row , int n,vector<string>&curr) {
        if(row == n){
       Count=Count+1;
            return;
        }
        
        for(int col=0;col<n;col++) {
            if(issafe(curr,row,col)) {
                curr[row][col] = 'Q';
                
                //recursive call to next row;
                backtrack(row+1,n,curr);
                //backtracting
                //before backtracking we are change the location with previous value 
                curr[row][col] = '.';
            }
        }
        
        return;
    }
    
    int totalNQueens(int n) {
           string s;
        for(int i=0;i<n;i++) 
            s=s+".";
        vector<string> curr(n,s);
        backtrack(0,n,curr);
        return Count;
    }
};