class Solution {
public:    
    void dfs(vector<vector<int>>& graph,  vector<vector<int>>& ans, vector<bool>& visited, int node,  vector<int>&pathsofar){
    
        if(node==graph.size()-1){
            ans.push_back(pathsofar);
            return;
        }

       visited[node]=true;
            for(int i=0; i<graph[node].size(); i++){
                if(visited[graph[node][i]]==false){
                      pathsofar.push_back(graph[node][i]);
                    dfs(graph, ans, visited, graph[node][i],pathsofar);
                 pathsofar.pop_back();
                }
            }
      visited[node]=false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<bool> visited(graph.size(),false);
        vector<vector<int>> ans; 
        vector<int>pathsofar;
        pathsofar.push_back(0);
        dfs(graph,ans,visited,0,pathsofar);
       
        return ans;
    }
};