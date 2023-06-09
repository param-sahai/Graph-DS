 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>distance(V, INT_MAX);// to store minimum distance of the vertex from the source
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //minheap priority queue {distance, node}
        distance[S]=0; //starting node
        pq.push({0,S});
        while(!pq.empty()){
            // pair<int, int> tp = pq.front();
            int top = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto it: adj[top]){
                //Relaxing the edges
                if(it[1]+dist < distance[it[0]]){
                    distance[it[0]] = it[1]+dist;
                    pq.push({distance[it[0]], it[0]});
                }
                
            }
        }
        return distance;
        
    }

// T.C. = E log V
