// Problem Link: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>dist(V, 1e8); //distance vector
        dist[S] = 0; //distance of the source from itself is 0
        
        //Relaxing the edges V-1 times
        // TC = V-1 * E === V*E
        for(int i=1;i<=V-1;i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u]!=1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u]+wt;
                }
            }
        }
        
        //Relaxing for Vth times for detecting negative edge cycles
        for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u]!=1e8 && dist[u] + wt < dist[v]){
                    return {-1};
                }
        }
        
        return dist;
    }
