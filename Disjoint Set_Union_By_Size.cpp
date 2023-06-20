#include <bits/stdc++.h>
using namespace std;
//   T.C. = O(1) Amortized
class DisjointSet{
  vector<int>parent, size;
  public:
   DisjointSet(int n){
       parent.resize(n+1);
       size.resize(n+1, 1);
       for(int i=0;i<=n;i++){
           parent[i] = i;
       }
   }
  
//   T.C. = O(4 * alpha)
   int findParent(int n){
       if(parent[n]==n) return n;
       else
       return parent[n] = findParent(parent[n]);
   }
 //   T.C. = O(4 * alpha)  
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
int main() {
    // Write C++ code here
    DisjointSet ds(7);
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);
    ds.UnionBySize(3,7);
    if(ds.findParent(3)==ds.findParent(7))
    cout<<"Same\n";
    else
    cout<<"Not Same\n";

    return 0;
}
