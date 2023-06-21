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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        
        unordered_map<string, int>mpMail;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mpMail.find(mail)==mpMail.end())
                    mpMail[mail] = i;
                else
                    ds.UnionBySize(i, mpMail[mail]);
            }
        }
        vector<string>mergedMail[n];
        for(auto it: mpMail){
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergedMail[node].push_back(mail);
        }
         vector<vector<string>>res;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }
            res.push_back(temp);
        }
        return res;
    }
};
