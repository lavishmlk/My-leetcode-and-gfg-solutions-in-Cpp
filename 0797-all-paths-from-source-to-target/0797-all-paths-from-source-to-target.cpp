//bina visited liye bhi kar sakta tha like in earlier solutions coz directed graph hai
//m1
class Solution {
public:    
    void dfs(vector<vector<int>>& graph,  vector<vector<int>>& ans, vector<bool>& visited, int node,  vector<int>&pathsofar){
    
        if(node==graph.size()-1){
            pathsofar.push_back(node);
            ans.push_back(pathsofar);
            pathsofar.pop_back();//dont forget to do a pop_back here
            return;
        }

       visited[node]=true;
            for(int i=0; i<graph[node].size(); i++){
                if(visited[graph[node][i]]==false){
                      pathsofar.push_back(node);
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
        dfs(graph,ans,visited,0,pathsofar);
       
        return ans;
    }
};

//m2 using archit way
// class Solution {
// public:    
//     void dfs(vector<vector<int>>& graph,  vector<vector<int>>& ans, vector<bool>& visited, int node,  vector<int>&pathsofar){
    
//         if(node==graph.size()-1){
//             ans.push_back(pathsofar);
//             return;
//         }

//        visited[node]=true;
//             for(int i=0; i<graph[node].size(); i++){
//                 if(visited[graph[node][i]]==false){
//                       pathsofar.push_back(graph[node][i]);
//                     dfs(graph, ans, visited, graph[node][i],pathsofar);
//                  pathsofar.pop_back();
//                 }
//             }
//       visited[node]=false;
//     }
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
//         vector<bool> visited(graph.size(),false);
//         vector<vector<int>> ans; 
//         vector<int>pathsofar;
//         pathsofar.push_back(0);
//         dfs(graph,ans,visited,0,pathsofar);
       
//         return ans;
//     }
// };

//m2 we pushed node instead of neighbour(graph[node][i])
// class Solution {
// public:    
//     void dfs(vector<vector<int>>& graph,  vector<vector<int>>& ans, vector<int>& visited, int node){
//         visited.push_back(node);//pep me call lagate hue push kia tha yahan preorder me kar rhe hai
//         if(node == graph.size()-1){//its same as source==destination
//             ans.push_back(visited);
//         }
//         else{
//             for(int i=0; i<graph[node].size(); i++){
//                 dfs(graph, ans, visited, graph[node][i]);
//             }
//         }
//         visited.pop_back(); 
//     }
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
//         vector<int> visited;
//         vector<vector<int>> ans; 
//         dfs(graph,ans,visited,0);
       
//         return ans;
//     }
// };

