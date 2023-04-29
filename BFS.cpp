class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>res;
        vector<bool> isVisited(V, false);
        queue<int> q;
        q.push(0);
        isVisited[0] = true;
        while(!q.empty()){
            int e = q.front();
            for(auto a: adj[e]){
                if(!isVisited[a]){
                    q.push(a);
                    isVisited[a] = true;
                }
            }
            res.push_back(e);
            // cout<<e<<" ";
            q.pop();
        }
        return res;
    }
};
