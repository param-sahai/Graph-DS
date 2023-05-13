class Solution {
public:
    
    bool checkTopoSort(int V, vector<int> adj[]) 
	{
        vector<int>indeg(V, 0);
	    // int indeg[V] = {0};
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
	    int count=0;
	    // vector<int>topo;
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
            count++;
	        // topo.push_back(front);
	        for(auto e: adj[front]){
	            indeg[e]--;
	            if(indeg[e]==0)
	            q.push(e);
	        }
	    }
        if(count==V) return true;
        else
	    return false;
	}
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        return checkTopoSort(numCourses, adj);
    }
};
