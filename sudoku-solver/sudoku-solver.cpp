class Solution {
public:
    char nboard[9][9];
    bool isValidrow(vector<vector<char>>& board,char x,int i,int j){
        
        for(int k=0;k<board[0].size();k++){
            if(board[i][k]==x){
                return false;
            }
        }
        
             for(int k=0;k<board.size();k++){
            if(board[k][j]==x){
                return false;
            }
        }
        
                int toplefti=(i/3)*3;
         int  topleftj=(j/3)*3;
        for(int k=0;k<3;k++){
            for(int p=0;p<3;p++){
            if(board[k+toplefti][p+topleftj]==x){
                return false;
            }
            }
        }
        
        return true;
        
    }
    
//        bool isValidcol(vector<vector<char>>& board,int x,int i,int j){
        
//         for(int k=0;k<board.size();k++){
//             if(board[k][j]==x){
//                 return false;
//             }
//         }
//         return true;
        
//     }
//        bool isValidsubbox(vector<vector<char>>& board,int x,int i,int j){
//         int toplefti=i/3*3;
//          int  topleftj=j/3*3;
//         for(int k=0;k<3;k++){
//             for(int p=0;p<3;p++){
//             if(board[k+toplefti][p+topleftj]==x){
//                 return false;
//             }
//             }
//         }
//         return true;
        
    // }
    
bool solution(vector<vector<char>>& board,int i,int j){
       
       
       
       if(i==board.size()){
    //           for(int x = 0; x < board.size(); x++){
    //   for(int y = 0; y < board[0].size(); y++){
    //    nboard[x][y]=board[x][y];
    //   }
    // }
           return true;
       }
       int ni=0;
       int nj=0;
       
        
        if(j==board.size()-1){
            ni=i+1;
            nj=0;
            
        }
        else{
            nj=j+1;
            ni=i;
        }
        
      
        if(board[i][j]=='.'){
              for(char k='1';k<='9';k++){
 if(isValidrow(board,k,i,j)==true){               
                   board[i][j]=k;
     if( solution(board,ni,nj)){
         return true;
     }
                      
              board[i][j]='.';
               }   
        }
              
    
        }
        else{
              return  solution(board,ni,nj);
        }
        
     return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solution(board,0,0);
    //        for(int x = 0; x < board.size(); x++){
    //   for(int y = 0; y < board[0].size(); y++){
    //    board[x][y]=nboard[x][y];
    //   }
    // }
        
    }
};