//Using Toposort approach
// Step 1 -  reverse the graph
// Step 2 - Apply Toposort technique



class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>revGraph[n];
        vector<int>indegree(n, 0);
        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                revGraph[it].push_back(i);
                indegree[i]++;
            }
        }
        
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int>safeNodes;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            safeNodes.push_back(front);
            for(auto it: revGraph[front]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
