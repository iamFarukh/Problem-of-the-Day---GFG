//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void dfscount(int row, int col, vector<vector<char>>& mat, vector<vector<int>>& vis, string target, int ind, int& ans){
       int n = mat.size();
       int m = mat[0].size();
       
       if(row<0 || row>=n || col<0 || col>=m || vis[row][col] || mat[row][col] != target[ind]){
           return;
       }
       
       vis[row][col]=1;
       if(target.size()-1==ind)  ans++;
       
       dfscount(row, col+1, mat, vis, target, ind+1, ans);
       dfscount(row-1, col, mat, vis, target, ind+1, ans);
       dfscount(row+1, col, mat, vis, target, ind+1, ans);
       dfscount(row, col-1, mat, vis, target, ind+1, ans);
       
       vis[row][col] = 0;
       
   }
   int findOccurrence(vector<vector<char> > &mat, string target){
       int n = mat.size();
       int m = mat[0].size();
       
       
       int ans=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               vector<vector<int>>vis(n, vector<int>(m,0));
               if(target[0]==mat[i][j]){
                   dfscount(i,j,mat,vis,target,0, ans);
                   
               }
           }
       }
       return ans;
   }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends
