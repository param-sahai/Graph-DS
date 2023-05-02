// problem link: https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    void dfs( queue<pair<int, int>> &q, vector<vector<char>> &grid, vector<vector<bool>> &isVisited, int m, int n)
    {
        while(!q.empty()){
            pair<int, int>p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            //checking left side
            if(i>=0 && (j-1)>=0 && !isVisited[i][j-1] && grid[i][j-1]=='1'){
                isVisited[i][j-1] = true;
                q.push({i, j-1});
            }
            
            //checking right side
            if(i>=0 && (j+1)<m && !isVisited[i][j+1] && grid[i][j+1]=='1'){
                isVisited[i][j+1] = true;
                q.push({i, j+1});
            }
            
            //checking top side
            if((i-1)>=0 && j>=0 && !isVisited[i-1][j] && grid[i-1][j]=='1'){
                isVisited[i-1][j] = true;
                q.push({i-1, j});
            }
            
            //checking bottom side
            if((i+1)<n && j>=0 && !isVisited[i+1][j] && grid[i+1][j]=='1'){
                isVisited[i+1][j] = true;
                q.push({i+1, j});
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>>q;
        
        int m = grid[0].size();
        int n = grid.size();
        
        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !isVisited[i][j]){
                    count+=1;
                    q.push({i,j});
                    isVisited[i][j]=true;
                    dfs(q, grid, isVisited, m, n);
                }
            }
        }
        return count;
    }
};
