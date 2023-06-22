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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int>stoneNodes;
        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.UnionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int cnt=0;
        for(auto it: stoneNodes){
            if(ds.findParent(it.first)==it.first)
                cnt++;
        }
        return n-cnt;
    }
};
