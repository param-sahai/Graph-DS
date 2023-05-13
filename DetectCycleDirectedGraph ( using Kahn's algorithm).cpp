class Solution {
  public:
  
  /**
    Here,we are making use of Kahn's Algorithm for finding out TopoSort of the given Graph
    We know that Kahn's algorithm only works on DAG, 
    so it will produce a topoSort list of size less than V for Cyclic Graphs
   **/
    bool checkTopoSort(int V, vector<int> adj[]) 
	{
	    int indeg[V] = {0};
	    for(int i=0;i<V;i++){
	        for(auto e: adj[i]){
	            indeg[e]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indeg[i]==0)
	        q.push(i);
	    }
	    
	    vector<int>topo;
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
	        topo.push_back(front);
	        for(auto e: adj[front]){
	            indeg[e]--;
	            if(indeg[e]==0)
	            q.push(e);
	        }
	    }
	    if(topo.size()==V) return false;
	    else return true;
	}
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        return checkTopoSort(V, adj);
    }
};
