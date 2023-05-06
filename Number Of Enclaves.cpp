//problem link: https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>&isVis){
        if(i<0 || j<0 || i>=n || j>=m || isVis[i][j] || grid[i][j]==0)
            return;
        if(!isVis[i][j] && grid[i][j]==1){
            isVis[i][j]=true;
            
            //dfs for all the 4 directions
            dfs(i-1, j, n, m, grid, isVis);
            dfs(i, j+1, n, m, grid, isVis);
            dfs(i+1, j, n, m, grid, isVis);
            dfs(i, j-1, n, m, grid, isVis);
        }
        return;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>isVis(n, vector<bool>(m, false));
        
        //Performing dfs for boundary 1's
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    if(grid[i][j]==1 && !isVis[i][j]){
                        dfs(i, j, n, m, grid, isVis);
                    }
                }
            }
        }
        
        int count=0;
        //Counting the number of 1s which haven't been Visited
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !isVis[i][j])
                    count+=1;
            }
        }
        return count;
    }
};
