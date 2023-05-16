//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
        //TopoSort function that will store the topoSort order in a stack
     void topoSort(int i, vector<int>&isVis, vector<pair<int,int>>adj[], stack<int>&st){
         isVis[i] = 1;
         for(auto it: adj[i]){
             int node = it.first;
             if(!isVis[node])
             topoSort(node, isVis, adj, st);
         }
         st.push(i);
     }
     
     vector<int> shortestPath(int N, int M, vector<vector<int>>& edges){
        // Creating adjacency List of the given weighted graph
        vector<pair<int, int>>adj[N];
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        //Performing TopoSort
        vector<int>isVis(N, 0);
        stack<int>st;
        
        for(int i=0;i<N;i++){
            if(!isVis[i])
            topoSort(i, isVis, adj, st);
        }
        
        //Now that the topoSort order has been stored in the stack, we will find the minimum cost/distance
        vector<int>dist(N, 1e9);
        dist[0] = 0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            for(auto it: adj[top]){
                int v = it.first;
                int wt = it.second;
                if(wt + dist[top] < dist[v])
                dist[v] = wt + dist[top];
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1e9)
            dist[i]=-1;
        }
        return dist;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
