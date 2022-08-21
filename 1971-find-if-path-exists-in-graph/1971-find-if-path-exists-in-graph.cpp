class Solution {
public:
  
     bool dfs(vector<vector<int>>& graph, vector<int>& visited, int current, int end) {
        if(current == end)
            return true;
        
        visited[current] = 1;
        
        for(int i=0; i<graph[current].size(); i++){//graph[current].size current row ka size de dega jaise //vector[0].SIZE IS 2 aur vector[1]1.size() is also 2 see //https://stackoverflow.com/questions/27340220/column-size-and-row-size-of-a-2d-vector-in-c
              if(visited[graph[current][i]]!=1){
            if(dfs(graph, visited, graph[current][i], end))
                return true;
        
        }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> graph(n);//isse shyd khali rows ka size initialize ho jaega agar column na karna ho to
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, 0);
        return dfs(graph, visited, start, end);
    }
};