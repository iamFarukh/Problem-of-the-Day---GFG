//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& g, int src){
        for(int i = 0; i < g[src].size(); i++){
            if(g[src][i] == 1){
                g[src][i] = -1;
                dfs(g, i);
            } 
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        int cnt = 0;
        for(int i = 0;i < V; i++){
            for(int j = 0; j < V; j++){
                if(adj[i][j] == 1){
                    adj[i][j] = -1;
                    cnt++;
                    dfs(adj, i);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
