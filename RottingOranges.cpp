//link: https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
    
        vector<vector<bool>>isVisited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<pair<int, int>, int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int cmax = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2 && !isVisited[i][j]){
                    q.push({{i,j},0});
                    isVisited[i][j]=true;
                }
            }
        }
        
                    while(!q.empty()){
                        bool flag = false;
                        pair<pair<int,int>, int> front = q.front();
                        q.pop();
                        int di = front.first.first;
                        int dj = front.first.second;
                        int count = front.second;
                        cmax = max(count, cmax);
                        //top
                        if(di-1>=0 && dj>=0 && grid[di-1][dj]==1 && !isVisited[di-1][dj]){
                            q.push({{di-1, dj}, count+1});
                            isVisited[di-1][dj]=true;
                            grid[di-1][dj]=2;
                            // flag = true;
                        }
                        //right
                        if(di>=0 && dj+1<m && grid[di][dj+1]==1 && !isVisited[di][dj+1]){
                            q.push({{di, dj+1}, count+1});
                            isVisited[di][dj+1]=true;
                            grid[di][dj+1]=2;
                            // flag = true;
                        }
                        //bottom
                        if(di+1<n && dj>=0 && grid[di+1][dj]==1 && !isVisited[di+1][dj]){
                            q.push({{di+1, dj}, count+1});
                            isVisited[di+1][dj]=true;
                            grid[di+1][dj]=2;
                            // flag = true;
                        }
                        //left
                        if(di>=0 && dj-1>=0 && grid[di][dj-1]==1 && !isVisited[di][dj-1]){
                            q.push({{di, dj-1}, count+1});
                            isVisited[di][dj-1]=true;
                            grid[di][dj-1]=2;
                            // flag = true;
                        }
                    }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        return cmax;
        
        
        
    }
};
