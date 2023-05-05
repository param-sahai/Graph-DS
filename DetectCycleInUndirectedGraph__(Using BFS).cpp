class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>isVisited(V, false);
        for(int i=0;i<V;i++){
            if(!isVisited[i]){
                isVisited[i]=true;
                queue<pair<int, int>>q;
                q.push({i, -1});
                while(!q.empty()){
                    pair<int, int>front = q.front();
                    q.pop();
                    for(auto e: adj[front.first]){
                        if(!isVisited[e]){
                            q.push({e, front.first});
                            isVisited[e] = true;
                        }
                        else if(isVisited[e] && e!=front.second)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        
        
      return false;  
    }
};
