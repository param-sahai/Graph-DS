// Problem link: https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
// USING FLOYD WARSHALL
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>distance(n, vector<int>(n, 1e9));
        
        // Storing the distance matrix values {from, to, distance}
        for(auto it:edges){
            distance[it[0]][it[1]] = it[2];
            distance[it[1]][it[0]] = it[2];
        }
        
        //Distance of a node to itself is always 0
        for(int i=0;i<n;i++){
            distance[i][i] = 0;
        }
        
        //Performing Floyd Warshall
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
                }
            }
        }
        
        //Finding the city with the minimum number of cities reachable from that city
        int minCount = INT_MAX;
        int count = 0, city = -1;
        for(int i=0;i<n;i++){
            count = 0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(distance[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=minCount){
                minCount = count;
                city = i;
            }
        }
        return city;
        // T.C. = O(N^3)
        // S.C. = O(N^2)
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends
