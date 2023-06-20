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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int count = 0; //count the number of extra links
		 //T.C = O(connections.size x 4 x alpha) 
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(ds.findParent(u)==ds.findParent(v))  //T.C = O(4 x alpha) = O(1)
                count++;
            else
                ds.UnionBySize(u, v);  //T.C = O(4 x alpha) = O(1)
        }
        int countIsolated = 0; //count the number of isolated or disconnected groups/nodes
		 //T.C = O(N)
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)
                countIsolated++;
        } 
        if(count >= countIsolated-1)
            return countIsolated-1;
        else
            return -1;
    }
};
