//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
    bool isValid(int adjr, int adjc, int n, int m){
        return (adjr>=0 && adjr<n && adjc>=0 & adjc<m);
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int isVis[n][m] ;
        memset(isVis, 0, sizeof isVis);
        int count=0;
        vector<int>ans;
        
        for(auto it: operators){
            int row = it[0];
            int col = it[1];
            if(isVis[row][col]==1){
                ans.push_back(count);
                continue;
            } 
            isVis[row][col] = 1;
            count++;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for(int i=0;i<4;i++){
                int adjr = row + dr[i];
                int adjc = col + dc[i];
                if(isValid(adjr, adjc, n, m)){
                    if(isVis[adjr][adjc]==1){
                        int nodeNo = row*m + col;
                        int adjnodeNo = adjr*m + adjc;
                        
                        if(ds.findParent(nodeNo)!=ds.findParent(adjnodeNo)){
                            count--;
                            ds.UnionBySize(nodeNo, adjnodeNo);
                        }
                    }
                    
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
