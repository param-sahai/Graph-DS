// problem link : https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    void bfs(vector<vector<int>>&isConnected, vector<bool>&isVisited, queue<int>&q){
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int e=0;e<isConnected[0].size();e++){
                if(isConnected[front][e]==1 && isVisited[e]==false){
                    q.push(e);
                    isVisited[e]=true;
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>isVisited(isConnected[0].size(), false);
        
        queue<int>q;
        int count=0;
        for(int x=0;x<isConnected[0].size();x++){
            if(!isVisited[x]){
                count+=1;
                isVisited[x]=true;
                q.push(x);
                bfs(isConnected, isVisited, q);
            }
        }
        return count;
        
    }
};
