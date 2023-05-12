https://leetcode.com/problems/find-eventual-safe-states/discuss/3517173/Simple-graph-dfs-traversal-with-comments

class Solution {
public:
    bool checkLoop(int i, vector<vector<int>>& graph, vector<int>&isVis, vector<int>&pathVis, vector<int>&safe){
        isVis[i] = 1;
        pathVis[i] = 1;
        //checking for adjacent nodes
        for(auto e: graph[i]){
            if(!isVis[e]){
                if(checkLoop(e, graph, isVis, pathVis, safe))
                    return true;
            }
            else if(isVis[e] && pathVis[e])
                return true;
        }
        
        //undoing the changes in path
        pathVis[i] = 0;
        
        //if dfs call has been reached till here, 
        //it means that element isn't in a loop
        //so mark it as safe node
        
        safe[i]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>isVis(n, 0); //for storing visited node
        vector<int>pathVis(n, 0); //for storing nodes that has been visited already in the current path
        vector<int>safe(n, 0); //for checking whther the node is safe or not
        vector<int>safeNodes; //storing safe nodes
        
        for(int i=0;i<n;i++){
            if(!isVis[i])
                checkLoop(i, graph, isVis, pathVis, safe);
        }
        for(int i=0;i<n;i++){
            if(safe[i]==1)
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
