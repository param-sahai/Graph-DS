// aka leetcode: O/1 Matrix Problem

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
	    int m=grid[0].size();
	    queue<pair<pair<int, int>, int>>q;
	    vector<vector<int>>res(n, vector<int>(m, 0));
	    vector<vector<bool>>isVisited(n, vector<bool>(m, false));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==0){
	                q.push({{i,j},0});
	                isVisited[i][j]=true;
	            }
	            
	        }
	    }
	    while(!q.empty()){
	        int di = q.front().first.first;
	        int dj = q.front().first.second;
	        int count = q.front().second;
            res[di][dj] = count;
	        q.pop();   
                //top
                if(di-1>=0 && dj>=0 && !isVisited[di-1][dj]){
                    q.push({{di-1, dj}, count+1});
                    isVisited[di-1][dj]=true;
                }
                //right
                if(di>=0 && dj+1<m && !isVisited[di][dj+1]){
                    q.push({{di, dj+1}, count+1});
                    isVisited[di][dj+1]=true;
                }
                //bottom
                if(di+1<n && dj>=0 && !isVisited[di+1][dj]){
                    q.push({{di+1, dj}, count+1});
                    isVisited[di+1][dj]=true;
                }
                //left
                if(di>=0 && dj-1>=0 && !isVisited[di][dj-1]){
                    q.push({{di, dj-1}, count+1});
                    isVisited[di][dj-1]=true;
                }
                        
            
	        
	    }
	    return res;
    }
};
