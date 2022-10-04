//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(vector<vector<int>>& grid , vector<vector<bool>> & vis, int i, int j,vector<pair<int,int>> &dir){
       
        int dx[] ={0,0,-1,1};
        int dy[] ={-1,1,0,0};
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({i,j});
     
        vis[i][j] = true;
        while(!q.empty()){
            auto f = q.front();
             int x  = f.first;
             int y = f.second ;
             dir.push_back({i-x,j-y}); //***** 
             q.pop();
             for(int k=0;k<4;k++){
                 int newx = x+dx[k];
                 int newy = y+ dy[k];
              if(newx>=0 && newx<m && newy>=0 && newy<n && grid[newx][newy]==1 && !vis[newx][newy] ){
                
                 q.push({newx,newy});
                  vis[newx][newy]=  true;
              }
              
             }
        }
    }
  
  
 
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        set< vector<pair<int,int>>  >  ss;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vector<pair<int,int>> dir ;//for each bfs call
                    bfs(grid,vis,i,j,dir);
                    ss.insert(dir);
                    dir.clear(); //for each bfs call , i want a new dir array
                }
            }
        }
        return ss.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
