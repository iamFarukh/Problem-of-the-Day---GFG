//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
   public:
    // Function to find unit area of the largest region of 1s.
    int r,c;

    bool issafe(int i,int j){
        return (i>=0 and i<r and j>=0 and j<c);
    }
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& vis,int count){
            int dx[]={1,-1,0,0  ,1, -1,1,-1};
            int dy[]={0, 0,1,-1 ,1 ,-1,-1,1};
    
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        count+=1;
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int xx=p.first;
            int yy=p.second;
            
            for(int i=0;i<8;i++){
                int nx=xx+dx[i];
                int ny=dy[i]+yy;
                
                if(issafe(nx,ny) and !vis[nx][ny] and grid[nx][ny]==1){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                    count+=1;
                }
            }
        }
        return count;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int ans=0;
        
        r=grid.size();
        c=grid[0].size();
        
        vector<vector<int>> vis(r,vector<int>(c,0));
        for(int i=0;i<r;i++) for(int j=0;j<c;j++){
            if(grid[i][j]==1 and !vis[i][j]){
                ans=max(ans,solve(grid,i,j,vis,0));
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
