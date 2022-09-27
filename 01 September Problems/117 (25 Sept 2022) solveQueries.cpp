//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Q) {
          // Code here
        vector<vector<int>> mat(n,vector<int> (n,0));
        for(auto &q:Q) {
            int a=q[0];
            int b=q[1];
            int c=q[2];
            int d=q[3];
            for(int row=a;row<=c;row++){
                mat[row][b]++;
                if(d+1<n)mat[row][d+1]--;
            }
        }
        for(int col=1;col<n;col++){
            for(int row=0;row<n;row++){
                mat[row][col]+=mat[row][col-1];
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++) {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++) cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends
