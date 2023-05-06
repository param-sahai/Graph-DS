//problem-link: https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<bool>>&isVis, vector<vector<char>>&board){
        
        //for border cases
        if(i<0 || j<0 || i>=n || j>=m || isVis[i][j] || board[i][j]=='X')
            return;
            
        
        if(!isVis[i][j] && board[i][j]=='O'){
            isVis[i][j] = true;
            
            //Searching in all 4 directions
            dfs(i-1, j, n, m, isVis, board);
            dfs(i, j+1, n, m, isVis, board);
            dfs(i+1, j, n, m, isVis, board);
            dfs(i, j-1, n, m, isVis, board);
        
        }
        
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>isVis(n, vector<bool>(m, false));
        
        
        
        /**
        Here we are performing dfs on all the nodes which are on the boundary
        and marking all those nodes which are connected to the boundary nodes
        
        In the end we are left with the unvisited nodes, which are not present on the boundary or         are 'X', indicated by isVis array..
        
        if [i,j] the node is Visited, i.e. isVis[i][j]=true, it means it is either a boundary node         are connected to a boundary node
        rest all the UnVisited Nodes are to be marked as 'X'
        **/
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if( board[i][j]=='O' && !isVis[i][j])
                    {
                        dfs(i, j, n, m, isVis, board);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!isVis[i][j])
                    board[i][j]='X';
            }
        }
        
    }
};
