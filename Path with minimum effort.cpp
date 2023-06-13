// Problem link: https://practice.geeksforgeeks.org/problems/path-with-minimum-effort
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue <pair<int,pair<int, int>>, 
        vector<pair<int, pair<int,int>>>, greater<pair<int,pair<int, int>>>> pq; //{dist, {row, col}}
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>distance (n , vector<int>(m, 1e9)); //minimum distance to reach [row][col]
        distance[0][0] = 0;
        pq.push({0, {0,0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!pq.empty()){
            int dist = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            if(r==n-1 && c==m-1) // the topmost element is the last element itself, i.e we have reached the destination, and upon further traversal, distance will only increase
            return distance[r][c];
            
            pq.pop();
            
            for(int i=0;i<4;i++){
                int newr = r + dr[i];
                int newc = c + dc[i];
                
                if(newr >= 0 && newr<n && newc >= 0 && newc<m){
                    int ht = heights[newr][newc];
                    int newEffort = max(abs(ht - heights[r][c]), dist);
        
                    if(newEffort<distance[newr][newc]){
                        distance[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        
        return distance[n-1][m-1];
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
