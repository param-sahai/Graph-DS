class Solution {
  public:
    bool dfs(int i, vector<bool>&isVis, vector<bool>&isPathVis, vector<int>adj[]){
        isVis[i] = true;
        isPathVis[i] = true;
        for(auto e: adj[i]){
            
            //if the node hasnt yet been visited, visit the node and perform df
            if(!isVis[e])
            {
                if(dfs(e, isVis, isPathVis, adj)==true)
                return true;
            }
            //if the node has already been visited and the node is present in the path
            else if(isVis[e] && isPathVis[e])
            return true;
            
        }
        
        //removing the node from the path
        isPathVis[i] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>isVis(V, false);
        vector<bool>isPathVis(V, false);
        for(int i=0;i<V;i++){
            //for connected components
            if(!isVis[i]){
                if(dfs(i, isVis, isPathVis, adj)==true)
                return true;
            }
        }
        return false;
    }
};
