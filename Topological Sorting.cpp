class Solution
{
	public:
	
	void dfs(int node, vector<int>adj[], vector<int>&isVis, stack<int>&st){
	    isVis[node] = 1;
	    for(auto e: adj[node]){
	        if(!isVis[e])
	        dfs(e, adj, isVis, st);
	    }
	    
	    //Pushing the node only after completion of the call stack
	    st.push(node);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>isVis(V, 0);
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!isVis[i])
	        dfs(i, adj, isVis, st);
	    }
	    vector<int>res;
	    while(!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
	}
};
