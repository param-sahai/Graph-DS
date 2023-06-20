//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
  vector<int>parent, size;
  public:
   DisjointSet(int n){
       parent.resize(n+1);
       size.resize(n+1, 1);
       for(int i=0;i<=n;i++){
           parent[i] = i;
       }
   }
   int findParent(int n){
       if(parent[n]==n) return n;
       else
       return parent[n] = findParent(parent[n]);
   }
   
   void UnionBySize(int u, int v){
       int parent_u = findParent(u);
       int parent_v = findParent(v);
       
       if(parent_u == parent_v) return;
       if(size[parent_v] > size[parent_u])
        {
            parent[parent_u] = parent_v;
            size[parent_v]+=size[parent_u];
        }
       else
        {
            parent[parent_v] = parent_u;
            size[parent_u]+=size[parent_v];
        }
       
   }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
//       O(M)
        vector<pair<int, pair<int,int>>>edges;
        
        //O(V+E)
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                int u = i;
                int v = it[0];
                int wt = it[1];
                edges.push_back({wt, {u, v}});
                // edges.push_back({wt, {v, u}});
            }
        }
        
        //Sorting the edges as per their weights (in ascending order)
//       M log M
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(V);
        int mstWt = 0;
        // V X 4 X alpha X 2
        for(auto it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findParent(u)!=ds.findParent(v)){
                mstWt+=wt;
                ds.UnionBySize(u, v);
            }
        }
        return mstWt;
        
    }
};

//{ Driver Code Starts.


int main() {

    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution obj;
    int mstWt = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}


// } Driver Code Ends
