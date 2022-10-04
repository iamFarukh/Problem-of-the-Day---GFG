//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int numberOfPaths(int m, int n){
        // code here
        long long mod=1e9+7;
        long long count[m][n];
      
        for (int i = 0; i < m; i++)
            count[i][0] = 1;
      
        for (int j = 0; j < n; j++)
            count[0][j] = 1;
      
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                count[i][j] = (count[i - 1][j] + count[i][j - 1])%mod;
        }
        return (count[m - 1][n - 1])%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
