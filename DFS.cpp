class Solution {
  public:
   //recursive dfs function
    void dfs(int V, vector<bool> &isVisited, vector<int> adj[], vector<int>&res){
        for(auto a:adj[V]){
            if(!isVisited[a]){
                isVisited[a] = true;
                res.push_back(a);
                dfs(a, isVisited, adj, res);
            }
        }
    }
    
    
     // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>res;
        vector<bool>isVisited (V, false);
        isVisited[0] = true;
        res.push_back(0);
        isVisited[0]=true;
        dfs(0, isVisited, adj, res);
        return res;
    }
};
