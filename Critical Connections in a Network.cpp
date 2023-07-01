class Solution {
    private:
    int timer = 1;
    void dfs(int node, int parent, vector<int>&isVis, vector<int> adj[], int tin[], int low[], vector<vector<int>>& bridges){
        
        isVis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it: adj[node]){
            if(it==parent) continue;
            if(!isVis[it]){
                dfs(it, node, isVis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);
                
                if(low[it] > tin[node])
                    bridges.push_back({it, node}); // if the lowest input time of adjNode is greater than the input time of the current node, then its a critical connection
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
    
    public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
       for(auto it: connections){
           int a = it[0];
           int b = it[1];
           adj[a].push_back(b);
           adj[b].push_back(a);
       }     
        vector<int>isVis(n, 0);
        int tin[n], low[n];
        vector<vector<int>>bridges;
        dfs(0, -1, isVis, adj, tin, low, bridges);
        
        return bridges;
    }
};
