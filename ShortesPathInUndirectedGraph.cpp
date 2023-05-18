//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // Using BFS trvrsal
        // creating an adjacency matrix
        vector<int>adj[N];
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //creating a distance matrix
        //initially storing infinite distance
        vector<int>dist(N, 1e9);
        dist[src] = 0;
        
        queue<pair<int, int>>q;
        q.push({src, 0});
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it: adj[front.first]){
                if(front.second + 1 < dist[it]){
                    dist[it] = front.second+1;
                    q.push({it, dist[it]});
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1e9)
            dist[i] = -1;
        }
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
