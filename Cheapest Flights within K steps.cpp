int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int, int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int>distance(n, 1e9);
        queue<pair<int, pair<int, int>>>q;
        //{stops, {dist, node}}
        
        //for starting node
        distance[src] = 0;
        q.push({0, {0,src}});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int stop = it.first;
            int dist = it.second.first;
            int node = it.second.second;
            
            if(stop>K) continue;
            for(auto iter: adj[node]){
                int adjNode = iter.first;
                int edgW = iter.second;
                
                if(edgW + dist < distance[adjNode] && stop<=K){
                    distance[adjNode] = edgW + dist;
                    q.push({stop+1, {edgW+dist, adjNode}});
                }
            }
            
        }
        if(distance[dst]==1e9)
        return -1;
        else return distance[dst];
        
    }
