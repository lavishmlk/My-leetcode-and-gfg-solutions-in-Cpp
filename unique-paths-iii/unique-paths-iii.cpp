// time com-> har cell ke pass 3 options hai but 1st ke pass 4 hai to  4*3*3*3....=3^(m+n)
//     space-m*n coz space is equal to the height of stack and in worst case stack can have all elements so m*n

class Solution {
public:
   typedef pair<int,int> Pair;

  int solution(int starti,int startj,vector<vector<int>>& grid,int initialcount){
   
      
         if(starti<0 || startj<0 || starti>=grid.size() || startj>=grid[0].size() || grid[starti][startj]==-1){
            return 0;
        }
      
        if(grid[starti][startj]==2){
            if( initialcount==-1)
          return 1;
            else
                return 0;
        }
        
     
        
      
        grid[starti][startj]=-1;
        initialcount--;
             int path1=solution(starti,startj+1,grid,initialcount);
             int path2=solution(starti+1,startj,grid,initialcount);
             int path3=solution(starti,startj-1,grid,initialcount);
             int path4=solution(starti-1,startj,grid,initialcount);

        initialcount++;
        grid[starti][startj]=0;
      
     int ans= path1+path2+path3+path4;
   return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
     
        
        
             int count=0;
        int starti=0;
            int startj=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    count++;
                }
               else if(grid[i][j]==1){
                    starti=i;
                    startj=j;
                }
               
           
            }  
        }
      return  solution(starti,startj,grid,count);
    }
};