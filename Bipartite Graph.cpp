// leetcode: Is Graph bipartite
// gfg : Bipartite Graph

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1); //for storing the color of the node
        queue<int>q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int f = q.front();
                    q.pop();
                    for(auto e: graph[f]){
                        if(color[e]==-1){
                            color[e] = !color[f];
                            q.push(e);
                        }
                        else if(color[e]==color[f])
                            return false;
                    }
            
                }
            }
        }
        return true;
    }
};
