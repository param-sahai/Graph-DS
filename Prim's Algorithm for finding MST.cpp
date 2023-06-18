// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; //{weight, node}
         int isVis[V] = {0}; //isVisited matrix to check whether the node has already been visited or not
         int cost = 0; //Calculate the total cost of the mst
         pq.push({0, 0}); //Starting from the 0th node with cost as 0
         
         //Using Prim's algorithm
         
         //E log E + E log E == E log E
         while(!pq.empty()){
             //log E
             int wt = pq.top().first;
             int node = pq.top().second;
             pq.pop();
             
             if(isVis[node]) continue; //skip the node if it has already been visited
             
             isVis[node] = 1; //mark the node as visited
             cost+=wt; //calculating the total cost
             
             //E log E
             for(auto it: adj[node]){
                 int adjNode = it[0];
                 int edW = it[1];
                 if(!isVis[adjNode])
                     pq.push({edW, adjNode});
             }
         }
         return cost;
         
         
         
    }
}; 

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
