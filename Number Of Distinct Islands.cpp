class Solution {
  public:
    void dfs(int i, int j, int n, int m, vector<vector<bool>>&isVis, vector<vector<int>>& grid, vector<pair<int, int>>&vec, int baseX, int baseY){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0 || isVis[i][j])
        return;
        isVis[i][j] = true;
        vec.push_back({i-baseX, j-baseY});
        dfs(i-1, j, n, m, isVis, grid, vec, baseX, baseY);
        dfs(i, j+1, n, m, isVis, grid, vec, baseX, baseY);
        dfs(i+1, j, n, m, isVis, grid, vec, baseX, baseY);
        dfs(i, j-1, n, m, isVis, grid, vec, baseX, baseY);
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int, int>>>st;
        vector<vector<bool>>isVis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!isVis[i][j] && grid[i][j]==1){
                    vector<pair<int, int>>vec; //vector that will store the relative coordinates
                    dfs(i, j, n, m, isVis, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
