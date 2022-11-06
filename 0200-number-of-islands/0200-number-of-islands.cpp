class Solution {
public:
    //tc-r*c
   void dfs(vector<vector<char>>& grid,vector<vector<bool>>&visited,int i,int j){
        
       if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0){
           return;
       }
       
      if(visited[i][j]==true || grid[i][j]=='0'){
          return;
      }
           visited[i][j]=true;
    
          dfs(grid,visited,i,j-1);
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i-1,j);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int count=0;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                  if(visited[i][j]==false && grid[i][j]=='1'){
                dfs(grid,visited,i,j);
                      count++;
                  }
            }
        }
        return count;
    }
};