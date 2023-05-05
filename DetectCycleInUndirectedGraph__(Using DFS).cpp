class Solution{
  public:
  bool dfs(int src, int parent, vector<int> adj[], vector<bool> &isVisited){
          isVisited[src] = true;
          for(auto e: adj[src]){
              if(!isVisited[e]){
                  isVisited[e] = true;
                  if(dfs(e, src, adj, isVisited)==true)
                  return true;
              }  
              else if(isVisited[e] && e!=parent){
                  return true;
              }
          }
          return false;
      }



      bool isCycle(int V, vector<int> adj[]) {
          // Code here
          vector<bool>isVisited(V, false);
          for(int i=0;i<V;i++){
              if(!isVisited[i]){
                  if(dfs(i, -1, adj, isVisited))
                  return true;
              }
          }

        return false;  
      }
};
