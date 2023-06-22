class DisjointSet{
  public:
  vector<int>parent, size;
   DisjointSet(int n){
       parent.resize(n+1);
       size.resize(n+1, 1);
       for(int i=0;i<=n;i++){
           parent[i] = i;
       }
   }
   int findParent(int n){
       if(parent[n]==n) return n;
       else
       return parent[n] = findParent(parent[n]);
   }
   
   void UnionBySize(int u, int v){
       int parent_u = findParent(u);
       int parent_v = findParent(v);
       
       if(parent_u == parent_v) return;
       if(size[parent_v] > size[parent_u])
        {
            parent[parent_u] = parent_v;
            size[parent_v]+=size[parent_u];
        }
       else
        {
            parent[parent_v] = parent_u;
            size[parent_u]+=size[parent_v];
        }
       
   }
};

class Solution {
public:
    bool isValid(int adjR, int adjC, int n, int m){
        return (adjR>=0 && adjR<n && adjC>=0 && adjC<m);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int mx = 0;
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);
        //Created a Disjoint Set of connected '1's
      // O(n x m x 4 x 4 alpha)
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for(int k=0;k<4;k++){
                    int adjR = i + dr[k];
                    int adjC = j + dc[k];
                    if(isValid(adjR, adjC, n, m) && grid[adjR][adjC]==1)
                    {
                        int node = i*m + j;
                        int adjNode = adjR*m + adjC;
                        ds.UnionBySize(node, adjNode);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                set<int>components;
                for(int k=0;k<4;k++){
                    int adjR = i + dr[k];
                    int adjC = j + dc[k];
                    if(isValid(adjR, adjC, n, m) && grid[adjR][adjC]==1)
                    {
                        components.insert(ds.findParent(adjR*m + adjC));
                    }
                }
                int countTotal = 1;
                for(auto it: components){
                    countTotal+=ds.size[it];
                }
                mx = max(countTotal, mx);
            }
        }
        return mx==0 ? n*m : mx;  //if all 1's
        
    }
};
