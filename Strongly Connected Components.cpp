//{ Driver Code Starts

/*
T.C = O(V+E) + O(V+E) + O(V+E) 
DFS + DFSAgain + Reverse

S.C. = O(V) + O(V) + O(V+E)
isVis +  Stack + ReversedMatrix
*/
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{ 
    // O(V+E)
   void dfs(int node, vector<bool> &isVis, vector<vector<int>>& adj, stack<int> &st) {
        isVis[node] = true;
    
        for (auto it : adj[node]) {
            if (!isVis[it]) {
                dfs(it, isVis, adj, st);
            }
        }
    
        st.push(node);
    }

    // O(V+E)
    void dfsAgain(int node, vector<bool> &isVis, vector<vector<int>>& adj) {
        isVis[node] = true;
    
        for (auto it : adj[node]) {
            if (!isVis[it]) {
                dfsAgain(it, isVis, adj);
            }
        }
    }
public:    
    int kosaraju(int V, vector<vector<int>>& adj) {
        vector<bool> isVis(V, false); //O(V)
        stack<int> st; //O(V)
    
        //Perform simple DFS // O(V+E) 
        for (int i = 0; i < V; i++) {
            if (!isVis[i]) {
                dfs(i, isVis, adj, st);
            }
        }
    
        //Reversing the edges of the graph // O(V+E)
        vector<vector<int>> adjR(V); // O(V+E) Space
        for (int i = 0; i < V; i++) {
            isVis[i]=0;
            for (auto it : adj[i]) {
                adjR[it].push_back(i);
            }
        }
        
        //Finding the number of strongly connected components
        int scc = 0;
    // O(V+E)
        while (!st.empty()) {
            int node = st.top();
            st.pop();
    
            if (!isVis[node]) {
                scc++;
                dfsAgain(node, isVis, adjR);
            }
        }
    
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
