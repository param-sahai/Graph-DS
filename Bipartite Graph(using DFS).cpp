class Solution {
public:
    bool dfs(int i, int col, vector<vector<int>>& graph, vector<int>&color){
        color[i] = col;
        
        for(auto e: graph[i]){
            if(color[e]==-1){
                if(dfs(e, !col, graph, color)==false) return false;
            }
            else if(color[e]==col)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1); //for storing the color of the node
        queue<int>q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i, 0, graph, color)==false) return false;
            }
        }
        return true;
    }
};
