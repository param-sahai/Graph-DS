// Problem Link: https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int  n =matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            
    	        if(matrix[i][j]==-1) //no edge from i->j
        	        matrix[i][j] = 1e9;
    	    
        	    if(i==j) matrix[i][j]=0; //self path
    	    }
        }
/*
TC = O(N*N*N)
Space = O(N*N) --- matrix[N*N]
*/
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
    	        for(int j=0;j<n;j++){
    	            matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
        	    }
            }
        }
        
        //Checking for negative edges
        // for(int j=0;j<n;j++){
    	   //         if(matrix[j][j]<0) 
    	   //         //Perform what needs to be done
        // }
        
        for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            
    	        if(matrix[i][j]==1e9) //no edge from i->j
        	        matrix[i][j] = -1;
    	    }
        }
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
